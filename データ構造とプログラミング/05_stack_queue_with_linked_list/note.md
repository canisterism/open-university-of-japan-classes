#  双方向連結リスト(doubly linked list)

- 双方向連結リストとは、双方向に連結されているリストのこと。
  - 一般に連結リストと言われるリストは先頭から末尾に向かって次のノードへの参照を持つが、双方向連結リストは前後のノードに対する参照を保持する。
  - ポインタが2つ必要なので挿入・削除にかかる操作が増える一方で、削除対象のノードの前のノードを知るのが簡単なので、前後のノードのポインタを繋ぎ変えるのが簡単になる。

```
        +-----+   +-----+   +-----+   +-----+
NULL <- |data1|<->|data2|<->|data3|<->|data4| -> NULL
        +-----+   +-----+   +-----+   +-----+ 
```

# 環状連結リスト(circular linked list)

- 単方向連結リストの末尾ノードが先頭ノードへの参照を持つリストを環状連結リストという。
  - 無限ループするのを防ぐために先頭ノードを指すポインタを保持するなどの工夫が必要

# 環状双方向連結リスト(circular doubly linked list)

- 上記の2つを組み合わせたデータ構造。
