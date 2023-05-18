#include<stdio.h>
#include<stdlib.h>
#define MAX_LIST_SIZE 100 // 리스트의 최대크기
typedef int element; // 항목의 정의
typedef struct {
	element array[MAX_LIST_SIZE]; // 배열 정의
	int size; // 현재 리스트에 저장된 항목들의 개수
} ArrayListType;

int number=0;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 리스트 초기화 함수
void init(ArrayListType* L)
{
	L->size = 0;
}
// 리스트가 비어 있으면 1을 반환
// 그렇지 않으면 0을 반환
int is_empty(ArrayListType* L)
{
	return L->size == 0;
}
// 리스트가 가득 차 있으면 1을 반환
// 그렇지 많으면 1을 반환
int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}
element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	return L->array[pos];
}
// 리스트 출력
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
		error("리스트 오버플로우");
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
	}else printf("ㅇㅗ류");
}
element delete(ArrayListType* L, int pos)
{
	element item;
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
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
	// ArrayListType를 정적으로 생성하고 ArrayListType를
	// 가리키는 포인터를 함수의 매개변수로 전달한다. 
	
	ArrayListType list;
	init(&list);
	
	while(1){
		number = 0;
		printf("선택 1_ 삽입  2_ 삭제  3_ 출력  0_ 종료 : ");
		int menu = 0;
		int a = 0, b = 0;
		scanf_s("%d", &menu);
		switch (menu) {
		case 1:
			printf("\n추가할 숫자와 위치를 입력하십시오 : ");
			scanf_s("%d %d", &a, &b);
			insert(&list, a, b);
			printf("\n이동 횟수는 %d\n", number);
			break;
		case 2:
			printf("\n삭제할 위치를 입력하십시오 : ");
			scanf_s(" %d", &b);
			delete(&list, b);
			printf("\n이동 횟수는 %d\n", number);
			break;
		case 3:
			print_list(&list);
			break;
		case 0: return 0;
		}
	}
}
