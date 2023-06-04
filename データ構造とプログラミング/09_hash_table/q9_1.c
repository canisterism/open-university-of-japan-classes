#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TABLE_SIZE 10

enum data_status
{
  EMPTY,
  OCCUPIED,
  DELETED
};

struct hash_table_type
{
  int data;
  enum data_status status;
};

typedef struct hash_table_type HASH_TABLE_TYPE;

int hash_function(int key)
{
  return (key % TABLE_SIZE);
}

void hash_table_init(HASH_TABLE_TYPE hash_table[])
{
  int i;
  for (i = 0; i < TABLE_SIZE; i++)
  {
    hash_table[i].status = EMPTY;
  }
}

void display(HASH_TABLE_TYPE hash_table[])
{
  int i;
  printf("----- hash table -----\n");
  for (i = 0; i < TABLE_SIZE; i++)
  {
    printf("[%02d]: ", i);
    if (hash_table[i].status == OCCUPIED)
    {
      printf("%02d\n", hash_table[i].data);
    }
    else if (hash_table[i].status == DELETED)
    {
      printf("deleted\n");
    }
    else
    {
      printf("empty\n");
    }
  }
  return;
}

void insert(int data, HASH_TABLE_TYPE hash_table[])
{
  int i, key, initial_index, index;
  key = data;

  initial_index = hash_function(key);
  index = initial_index;
  for (i = 1; i < TABLE_SIZE - 1; i++)
  {
    // 空いてたらデータを保存して終了
    if (hash_table[index].status == EMPTY || hash_table[index].status == DELETED)
    {
      printf("Index %02d is vacant.", index);
      hash_table[index].data = data;
      hash_table[index].status = OCCUPIED;
      printf("Inserted %02d\n", data);
      return;
    }
    // 同じデータなので保存せず終了
    if (hash_table[index].data == data)
    {
      printf("%d is same data.\n", data);
      return;
    }
    // ハッシュが衝突したので線形探査で空きを探す
    printf("Index %02d collided. Increment index...\n", index);
    index = (initial_index + i) % TABLE_SIZE;
  }
  printf("ERROR: table size limit exceeded [%d]\n", TABLE_SIZE);
  exit(-1);
}
// ハッシュテーブルからデータを探索してindexを返す関数。
int search(int data, HASH_TABLE_TYPE hash_table[])
{
  int i, key, initial_index, index;
  key = data;

  initial_index = hash_function(key);
  index = initial_index;
  for (i = 1; i < TABLE_SIZE - 1; i++)
  {
    if (hash_table[index].status == OCCUPIED)
    {
      printf("Found %d at [%02d]\n", data, index);
      return index;
    }
    printf("Not Found %d at index %02d. Searching next address.\n", data, index);
    index = (initial_index + i) % TABLE_SIZE;
  }

  return -1; // notfound
}

void delete(int data, HASH_TABLE_TYPE hash_table[])
{
  int index;
  index = search(data, hash_table);
  if (index == -1)
  {
    printf("Not Found %d\n", data);
    return;
  }
  else
  {
    hash_table[index].status = DELETED;
    printf("Deleted %d \n", data);
  }
}

int main()
{
  int i, key, data, index;
  HASH_TABLE_TYPE hash_table[TABLE_SIZE];

  hash_table_init(hash_table);

  srand(time(NULL));

  for (i = 0; i < 10; i++)
  {
    data = rand() % 1000;
    printf("Inserting %d...\n", data);
    insert(data, hash_table);
  }

  display(hash_table);

  key = data;
  printf("Deleting %d...\n", key);
  delete (key, hash_table);

  return 0;
}
