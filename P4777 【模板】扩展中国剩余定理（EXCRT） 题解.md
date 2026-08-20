# P4777 【模板】扩展中国剩余定理（EXCRT） 题解

逐个合并同余式。已有 $x\equiv r\pmod m$，新式为 $x\equiv b\pmod a$，则需解 $mt\equiv b-r\pmod a$；扩展欧几里得求 $t$，更新模数为最小公倍数。乘法使用 `__int128` 防止中间溢出。
