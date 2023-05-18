#include<stdio.h>
#include<stdlib.h>
#define MAX_LIST_SIZE 100 // ����Ʈ�� �ִ�ũ��
typedef int element; // �׸��� ����
typedef struct {
	element array[MAX_LIST_SIZE]; // �迭 ����
	int size; // ���� ����Ʈ�� ����� �׸���� ����
} ArrayListType;

int number=0;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// ����Ʈ �ʱ�ȭ �Լ�
void init(ArrayListType* L)
{
	L->size = 0;
}
// ����Ʈ�� ��� ������ 1�� ��ȯ
// �׷��� ������ 0�� ��ȯ
int is_empty(ArrayListType* L)
{
	return L->size == 0;
}
// ����Ʈ�� ���� �� ������ 1�� ��ȯ
// �׷��� ������ 1�� ��ȯ
int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}
element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("��ġ ����");
	return L->array[pos];
}
// ����Ʈ ���
void print_list(ArrayListType* L)
{
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}
void insert_last(ArrayListType* L, element item)
{
	if (L->size >= MAX_LIST_SIZE) {
		error("����Ʈ �����÷ο�");
	}
	L->array[L->size++] = item;
}
void insert(ArrayListType* L, int pos, element item)
{
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--) {
			L->array[i + 1] = L->array[i];
			number++;
		}
		L->array[pos] = item;
		L->size++;
	}else printf("���Ƿ�");
}
element delete(ArrayListType* L, int pos)
{
	element item;
	if (pos < 0 || pos >= L->size)
		error("��ġ ����");
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++) {
		L->array[i] = L->array[i + 1];
		number++;
	}
	L->size--;
	return item;
}
int main(void)
{
	// ArrayListType�� �������� �����ϰ� ArrayListType��
	// ����Ű�� �����͸� �Լ��� �Ű������� �����Ѵ�. 
	
	ArrayListType list;
	init(&list);
	
	while(1){
		number = 0;
		printf("���� 1_ ����  2_ ����  3_ ���  0_ ���� : ");
		int menu = 0;
		int a = 0, b = 0;
		scanf_s("%d", &menu);
		switch (menu) {
		case 1:
			printf("\n�߰��� ���ڿ� ��ġ�� �Է��Ͻʽÿ� : ");
			scanf_s("%d %d", &a, &b);
			insert(&list, a, b);
			printf("\n�̵� Ƚ���� %d\n", number);
			break;
		case 2:
			printf("\n������ ��ġ�� �Է��Ͻʽÿ� : ");
			scanf_s(" %d", &b);
			delete(&list, b);
			printf("\n�̵� Ƚ���� %d\n", number);
			break;
		case 3:
			print_list(&list);
			break;
		case 0: return 0;
		}
	}
}
