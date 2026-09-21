# SDD ledger — plan: sublime-cph implementation

Pre-flight: new independent repository under /home/tangyixiao/Code; no shared tracked interfaces with parent Code repo.

Task 1: complete (commits b89c796..53561ea, tests: python3 -m unittest discover -s tests -v -> 6 passed)
Final review: self-review (no subagent tool); HTTP integration, static checks, and isolated installer check passed.
Ruling: keep the Sublime package as a symlink to the GitHub worktree — Sublime's package documentation supports symlinked loose packages and this keeps local development updates immediate.
Ruling: retain manual listener startup — automatic startup would contend with CP Editor's existing port 10045 listener when both applications are used.
