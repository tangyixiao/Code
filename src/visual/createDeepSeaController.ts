import type { BufferGeometry, Material, Object3D, Texture, WebGLRenderer } from 'three'
import { createResourceScope } from './resourceScope'
import type { DeepSeaCanvasProps, DeepSeaController, ScenePhase } from './types'

export const PARTICLE_COUNT = 360

type Target = { cameraX: number; cameraY: number; cameraZ: number; tilt: number; drift: number }
const TARGETS: Record<ScenePhase, Target> = {
  hero: { cameraX: 0.1, cameraY: 0.1, cameraZ: 11, tilt: 0.2, drift: 0.25 },
  orbit: { cameraX: -0.8, cameraY: 0.5, cameraZ: 10.5, tilt: 0.55, drift: 0.42 },
  focus: { cameraX: 0.9, cameraY: -0.6, cameraZ: 12, tilt: -0.35, drift: 0.62 },
  archive: { cameraX: -0.35, cameraY: -0.15, cameraZ: 10, tilt: 0.8, drift: 0.78 },
  links: { cameraX: 0.35, cameraY: 0.75, cameraZ: 11.5, tilt: -0.7, drift: 0.92 },
  workbench: { cameraX: 0, cameraY: 0, cameraZ: 9.5, tilt: 0, drift: 1 },
}

const seeded = (index: number) => {
  const value = Math.sin(index * 12.9898 + 78.233) * 43758.5453
  return value - Math.floor(value)
}

export async function createDeepSeaController(canvas: HTMLCanvasElement, props: DeepSeaCanvasProps, onContextLost: () => void, onRender?: (count: number) => void): Promise<DeepSeaController> {
  const THREE = await import('three')
  let renderer: WebGLRenderer
  try {
    renderer = new THREE.WebGLRenderer({ canvas, alpha: true, antialias: true, powerPreference: 'high-performance' })
  } catch (error) {
    throw new Error('Deep-sea WebGL renderer could not initialize', { cause: error })
  }

  const scope = createResourceScope()
  scope.add(() => { renderer.setAnimationLoop(null); renderer.renderLists.dispose(); renderer.dispose() })
  try {
    const scene = new THREE.Scene()
    scene.fog = new THREE.FogExp2(0x031425, 0.065)
    const camera = new THREE.PerspectiveCamera(42, 1, 0.1, 80)
    const world = new THREE.Group()
    const nucleusGroup = new THREE.Group()
    const orbitGroup = new THREE.Group()
    const objects: Object3D[] = [world, nucleusGroup, orbitGroup]

    const rememberGeometry = <T extends BufferGeometry>(geometry: T) => { scope.add(() => geometry.dispose()); return geometry }
    const disposeMaterial = (material: Material) => {
      for (const value of Object.values(material)) if (value && typeof value === 'object' && 'isTexture' in value) (value as Texture).dispose()
      material.dispose()
    }
    const rememberMaterial = <T extends Material>(material: T) => { scope.add(() => disposeMaterial(material)); return material }

    const nucleus = new THREE.Mesh(rememberGeometry(new THREE.IcosahedronGeometry(1.12, 3)), rememberMaterial(new THREE.MeshBasicMaterial({ color: 0x56d9f4, transparent: true, opacity: 0.58, wireframe: true })))
    const halo = new THREE.Mesh(rememberGeometry(new THREE.SphereGeometry(1.85, 24, 16)), rememberMaterial(new THREE.MeshBasicMaterial({ color: 0x37bbef, transparent: true, opacity: 0.065, depthWrite: false, blending: THREE.AdditiveBlending })))
    const nucleusLight = new THREE.PointLight(0x45d9ff, 2.8, 15, 2)
    const violetLight = new THREE.PointLight(0x716cff, 1.4, 13, 2)
    nucleusGroup.add(nucleus, halo, nucleusLight, violetLight)
    world.add(nucleusGroup)
    objects.push(nucleus, halo, nucleusLight, violetLight)

    const makeOrbit = (radiusX: number, radiusY: number, color: number, opacity: number, rotation: [number, number, number]) => {
      const curve = new THREE.EllipseCurve(0, 0, radiusX, radiusY, 0, Math.PI * 2, false, 0)
      const points = curve.getPoints(96).map((point) => new THREE.Vector3(point.x, point.y, 0))
      const line = new THREE.LineLoop(rememberGeometry(new THREE.BufferGeometry().setFromPoints(points)), rememberMaterial(new THREE.LineBasicMaterial({ color, transparent: true, opacity })))
      line.rotation.set(...rotation)
      orbitGroup.add(line)
      objects.push(line)
    }
    makeOrbit(4.6, 1.45, 0x51dfff, 0.2, [0.55, 0.2, 0.12])
    makeOrbit(3.5, 2.3, 0x7773ff, 0.19, [-0.25, 0.8, -0.32])
    makeOrbit(5.8, 3.5, 0x7292b2, 0.09, [1.15, -0.45, 0.42])
    world.add(orbitGroup)

    const positions = new Float32Array(PARTICLE_COUNT * 3)
    const bases = new Float32Array(PARTICLE_COUNT * 3)
    const seeds = new Float32Array(PARTICLE_COUNT)
    for (let i = 0; i < PARTICLE_COUNT; i += 1) {
      const seed = seeded(i)
      const angle = seeded(i + 1000) * Math.PI * 2
      const radius = 2.8 + seeded(i + 2000) * 6.2
      const offset = i * 3
      bases[offset] = positions[offset] = Math.cos(angle) * radius
      bases[offset + 1] = positions[offset + 1] = (seeded(i + 3000) - 0.5) * 7
      bases[offset + 2] = positions[offset + 2] = Math.sin(angle) * radius - 1.5
      seeds[i] = seed
    }
    const particleGeometry = rememberGeometry(new THREE.BufferGeometry())
    const attribute = new THREE.BufferAttribute(positions, 3)
    particleGeometry.setAttribute('position', attribute)
    const particles = new THREE.Points(particleGeometry, rememberMaterial(new THREE.PointsMaterial({ color: 0x66cde8, size: 0.045, transparent: true, opacity: 0.38, depthWrite: false, blending: THREE.AdditiveBlending })))
    particles.frustumCulled = false
    world.add(particles)
    objects.push(particles)

    const signal = new THREE.Mesh(rememberGeometry(new THREE.TorusGeometry(1.7, 0.012, 8, 96)), rememberMaterial(new THREE.MeshBasicMaterial({ color: 0x62ddff, transparent: true, opacity: 0.48 })))
    signal.rotation.set(Math.PI / 2, 0.2, 0.4)
    world.add(signal)
    objects.push(signal)
    scene.add(world)

    const pointer = { x: 0, y: 0 }
    const pointerTarget = { x: 0, y: 0 }
    let target = TARGETS[props.phase]
    let pulseEnergy = 0
    let pulseSeed = props.pulse
    let destroyed = false
    let running = false
    let visible = !document.hidden
    let frameId = 0
    let count = 0
    const resize = () => {
      const width = Math.max(innerWidth, 1)
      const height = Math.max(innerHeight, 1)
      camera.aspect = width / height
      camera.updateProjectionMatrix()
      renderer.setPixelRatio(Math.min(devicePixelRatio, 2))
      renderer.setSize(width, height, false)
    }
    const onPointer = (event: PointerEvent) => {
      pointerTarget.x = (event.clientX / Math.max(innerWidth, 1) - 0.5) * 2
      pointerTarget.y = (event.clientY / Math.max(innerHeight, 1) - 0.5) * -2
    }
    const render = (time: number) => {
      if (destroyed) return
      const seconds = time * 0.001
      const rate = props.reducedMotion ? 1 : 0.055
      pointer.x += (pointerTarget.x - pointer.x) * (props.reducedMotion ? 1 : 0.045)
      pointer.y += (pointerTarget.y - pointer.y) * (props.reducedMotion ? 1 : 0.045)
      camera.position.x += ((target.cameraX + pointer.x * 0.2) - camera.position.x) * rate
      camera.position.y += ((target.cameraY + pointer.y * 0.16) - camera.position.y) * rate
      camera.position.z += (target.cameraZ - camera.position.z) * rate
      if (!props.reducedMotion) { camera.position.x += Math.sin(seconds * 0.16) * 0.002; camera.position.y += Math.cos(seconds * 0.14) * 0.002 }
      camera.lookAt(0, 0, 0)
      world.rotation.y += ((pointer.x * 0.08 + target.tilt * 0.05) - world.rotation.y) * rate
      world.rotation.x += (pointer.y * 0.045 - world.rotation.x) * rate
      nucleusGroup.rotation.y = props.reducedMotion ? 0 : seconds * 0.12
      const scale = 1 + pulseEnergy * (0.14 + Math.sin(pulseSeed * 1.7) * 0.03)
      nucleusGroup.scale.setScalar(scale)
      pulseEnergy *= props.reducedMotion ? 0 : 0.94
      signal.rotation.z = props.reducedMotion ? 0 : seconds * 0.08
      signal.scale.setScalar(1 + pulseEnergy * 0.4)
      for (let i = 0; i < PARTICLE_COUNT; i += 1) {
        const offset = i * 3
        const seed = seeds[i]
        const flow = seconds * (0.08 + seed * 0.08) * target.drift
        positions[offset] = bases[offset] + Math.sin(flow + seed * 12) * 0.25 + pointer.x * seed * 0.08
        positions[offset + 1] = bases[offset + 1] + Math.cos(flow * 1.3 + seed * 8) * 0.2 + pointer.y * seed * 0.08
        positions[offset + 2] = bases[offset + 2] + Math.sin(flow * 0.7 + seed * 15) * 0.35
      }
      attribute.needsUpdate = true
      renderer.render(scene, camera)
      count += 1
      onRender?.(count)
    }
    const loop = (time: number) => {
      if (destroyed || !visible || props.reducedMotion) { running = false; frameId = 0; return }
      render(time)
      frameId = requestAnimationFrame(loop)
    }
    const start = () => { if (!destroyed && visible && !props.reducedMotion && !running) { running = true; frameId = requestAnimationFrame(loop) } }
    const stop = () => { if (frameId) cancelAnimationFrame(frameId); frameId = 0; running = false }
    const onVisibility = () => {
      visible = !document.hidden
      if (!visible) stop()
      else if (!props.reducedMotion) { render(performance.now()); start() }
    }
    const onContext = (event: Event) => { event.preventDefault(); stop(); onContextLost() }
    resize()
    addEventListener('resize', resize, { passive: true }); scope.add(() => removeEventListener('resize', resize))
    addEventListener('pointermove', onPointer, { passive: true }); scope.add(() => removeEventListener('pointermove', onPointer))
    document.addEventListener('visibilitychange', onVisibility); scope.add(() => document.removeEventListener('visibilitychange', onVisibility))
    canvas.addEventListener('webglcontextlost', onContext, { passive: false }); scope.add(() => canvas.removeEventListener('webglcontextlost', onContext))
    renderer.setClearColor(0x000000, 0)
    render(0)
    start()
    const setPhase = (phase: ScenePhase) => { target = TARGETS[phase] }
    const pulse = (seed: number) => { pulseSeed = Number.isFinite(seed) ? seed : 0; pulseEnergy = 1 }
    const destroy = () => { if (destroyed) return; destroyed = true; stop(); try { for (const object of objects) object.clear(); scope.cleanup() } catch { /* best effort teardown */ } }
    return { setPhase, pulse, destroy }
  } catch (error) {
    try { scope.cleanup() } catch { /* preserve initialization error */ }
    throw error
  }
}
