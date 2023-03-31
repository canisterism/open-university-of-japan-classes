# これは何
「データ構造とプログラミング」の教科書の演習問題を解くリポジトリ。

# 環境構築

以下VSCodeを実行環境とする。

- cをコンパイル及び実行するために拡張を入れる。
  https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools
- 下記スニペットを `hello.c` などの名前で作る

```c
#include <stdio.h>

main()
{
  printf("Hello World\n");
}
```
- `gcc hello.c -o hello` を実行してコンパイルが実行されることを確認する。
- `./hello` を実行して生成されたファイルを呼び出し、`Hello World`が出力されることを確認する。


# 使い方

1. 章や問題番号に沿った名前の.cファイルを作成する
2. コードを書く
3. コンパイルして実行する

# Tips

- Code Runner の拡張を入れておくとコンパイルと実行をショートカットキーで行えるので便利
  - https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner
