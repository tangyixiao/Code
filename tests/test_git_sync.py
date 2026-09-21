import sys
import unittest
from pathlib import Path


sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from git_sync import build_commit_message, timestamp_now


class GitSyncTests(unittest.TestCase):
    def test_timestamp_has_millisecond_precision(self):
        timestamp = timestamp_now()
        self.assertRegex(timestamp, r"^\d{4}-\d{2}-\d{2}-\d{2}-\d{2}-\d{2}-\d{3}$")

    def test_commit_message_contains_changed_files(self):
        message = build_commit_message(
            "2026-09-21-16-00-00-123",
            ["M\tREADME.md", "A\tnew file.cpp"],
        )
        self.assertIn("2026-09-21-16-00-00-123", message)
        self.assertIn("M\tREADME.md", message)
        self.assertIn("A\tnew file.cpp", message)


if __name__ == "__main__":
    unittest.main()
