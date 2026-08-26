import assert from 'node:assert/strict'
import test from 'node:test'
import { createResourceScope } from '../src/visual/resourceScope.ts'

test('resource scope cleans every resource in reverse order and only once', () => {
  const calls = []
  const scope = createResourceScope()
  scope.add(() => calls.push('renderer'))
  scope.add(() => calls.push('canvas-listener'))
  scope.cleanup()
  scope.cleanup()
  assert.deepEqual(calls, ['canvas-listener', 'renderer'])
})

test('resource scope continues cleanup after a disposer throws', () => {
  const calls = []
  const scope = createResourceScope()
  scope.add(() => calls.push('first'))
  scope.add(() => { calls.push('throws'); throw new Error('driver failed') })
  scope.add(() => calls.push('last'))
  assert.throws(() => scope.cleanup(), /driver failed/)
  assert.deepEqual(calls, ['last', 'throws', 'first'])
})
