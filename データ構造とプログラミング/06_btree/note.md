# バイナリサーチツリー

- 二分探索木とは、各ノードがデータ（キー）を持ち、以下の性質を満たす木構造である。
  - left, right, parent属性を持つ。
  - leftのサブツリーに含まれるすべてのノードのデータは親となるノードのデータよりも小さい。
  - rightのサブツリーに含まれるすべてのノードのデータは親となるノードのデータよりも大きい。

# 最小値と最大値

- 最小値はleft属性を、最大値はright属性を辿っていって、Noneになったノードのデータが最小値、最大値となる。


# 走査

## 通りがけ走査

- node.left, node, node.rightを辿っていく。
- つまり、最小値から最大値の順番で走査することになる。

## 帰りがけ走査

- node.left, node.right, nodeを辿っていく。
- 二分木全体を削除するとき、帰りがけ走査を使うと、葉のノードから順番に削除できるのでメモリ効率が良い。

  ## 行きがけ走査

- node, node.left, node.rightを辿っていく。
