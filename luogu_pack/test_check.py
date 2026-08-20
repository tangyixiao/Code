import unittest

from luogu_pack.check import base_name, unique_rows, required_files


class CheckTest(unittest.TestCase):
    def test_base_name_replaces_special_characters(self):
        self.assertEqual(base_name('P1', '[A/B]: X?'), 'P1 [A_B]_ X_')

    def test_base_name_collapses_underscores(self):
        self.assertEqual(base_name('P1', 'A//B'), 'P1 A_B')

    def test_unique_rows_keeps_first_occurrence(self):
        a = [('P1', 'A', 'u1'), ('P2', 'B', 'u2'), ('P1', 'C', 'u3')]
        self.assertEqual(unique_rows(a), a[:2])

    def test_required_files(self):
        b = 'P1 A'
        self.assertEqual(required_files(b), [
            f'{b}.md', f'{b} 题解.md', f'{b}.cpp',
            f'{b} 数据生成.cpp', f'{b} 暴力.cpp', f'{b} 对拍.cpp'
        ])


if __name__ == '__main__':
    unittest.main()
