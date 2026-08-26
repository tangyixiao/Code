import { useEffect, useRef, useState } from 'react'
import type { DeepSeaCanvasProps, DeepSeaController } from './types'

const ASCII_ATOM = '   ·  .  ·\n .  /\\ /\\  .\n·  <  ◉  >  ·\n .  \\/ \\/  .\n   ·  |  ·'
export interface DeepSeaCanvasRuntimeProps extends DeepSeaCanvasProps { onFallback?: () => void }

export default function DeepSeaCanvas({ variant, phase, pulse, reducedMotion, onFallback }: DeepSeaCanvasRuntimeProps) {
  const canvasRef = useRef<HTMLCanvasElement>(null)
  const rootRef = useRef<HTMLDivElement>(null)
  const controllerRef = useRef<DeepSeaController | null>(null)
  const latestPhase = useRef(phase)
  const latestPulse = useRef(pulse)
  const appliedPulse = useRef<number | null>(null)
  const [fallback, setFallback] = useState(false)
  const [controllerPhase, setControllerPhase] = useState<string | null>(null)
  const [controllerPulse, setControllerPulse] = useState<number | null>(null)
  const renderCountRef = useRef(0)
  latestPhase.current = phase
  latestPulse.current = pulse

  const applyLatest = (controller: DeepSeaController) => {
    controller.setPhase(latestPhase.current)
    setControllerPhase(latestPhase.current)
    if (latestPulse.current > 0 && appliedPulse.current !== latestPulse.current) {
      controller.pulse(latestPulse.current)
      appliedPulse.current = latestPulse.current
      setControllerPulse(latestPulse.current)
    }
  }

  useEffect(() => {
    let disposed = false
    const canvas = canvasRef.current
    if (!canvas) return undefined
    appliedPulse.current = null
    setFallback(false)
    setControllerPhase(null)
    setControllerPulse(null)
    renderCountRef.current = 0
    rootRef.current?.setAttribute('data-scene-render-count', '0')
    rootRef.current?.setAttribute('data-scene-controller-pulse-count', '0')
    const showFallback = () => {
      if (disposed) return
      controllerRef.current?.destroy()
      controllerRef.current = null
      setFallback(true)
      onFallback?.()
    }
    import('./createDeepSeaController').then(({ createDeepSeaController }) => createDeepSeaController(canvas, { variant, phase: latestPhase.current, pulse: latestPulse.current, reducedMotion }, showFallback, (count) => {
      if (disposed) return
      rootRef.current?.setAttribute('data-scene-render-count', String(count))
      renderCountRef.current = count
    })).then((controller) => {
      if (disposed) { controller.destroy(); return }
      controllerRef.current = controller
      applyLatest(controller)
      rootRef.current?.setAttribute('data-scene-controller-pulse-count', appliedPulse.current === null ? '0' : '1')
    }).catch(showFallback)
    return () => { disposed = true; controllerRef.current?.destroy(); controllerRef.current = null }
  }, [onFallback, reducedMotion, variant])

  useEffect(() => {
    latestPhase.current = phase
    if (controllerRef.current) { controllerRef.current.setPhase(phase); setControllerPhase(phase) }
  }, [phase])
  useEffect(() => {
    latestPulse.current = pulse
    if (!controllerRef.current || pulse <= 0 || appliedPulse.current === pulse) return
    controllerRef.current.pulse(pulse)
    appliedPulse.current = pulse
    setControllerPulse(pulse)
    rootRef.current?.setAttribute('data-scene-controller-pulse-count', '1')
  }, [pulse])

  return <div ref={rootRef} className="deep-sea-scene" data-scene-root="" data-scene-variant={variant} data-scene-phase={phase} data-scene-motion={reducedMotion ? 'reduced' : 'full'} data-scene-animation={reducedMotion ? 'static' : 'running'} data-scene-pulse={pulse.toFixed(3)} data-scene-controller-phase={controllerPhase ?? 'loading'} data-scene-controller-pulse={controllerPulse === null ? 'loading' : controllerPulse.toFixed(3)} data-scene-controller-pulse-count="0" data-scene-render-count={renderCountRef.current} data-scene-fallback={fallback ? 'active' : 'inactive'} data-scene-particles={360} aria-hidden="true">
    <canvas ref={canvasRef} className="deep-sea-canvas" data-scene-canvas="" />
    <div className="deep-sea-fallback" aria-label={fallback ? 'Deep-sea scene fallback' : undefined}><span className="deep-sea-fallback-gradient" /><pre>{ASCII_ATOM}</pre></div>
  </div>
}
