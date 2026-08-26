export function createResourceScope() {
  const disposers: Array<() => void> = []
  let cleaned = false
  return {
    add(disposer: () => void) {
      if (cleaned) {
        disposer()
        return
      }
      disposers.push(disposer)
    },
    cleanup() {
      if (cleaned) return
      cleaned = true
      let firstError: unknown
      for (const disposer of disposers.reverse()) {
        try { disposer() } catch (error) { firstError ??= error }
      }
      if (firstError) throw firstError
    },
  }
}
