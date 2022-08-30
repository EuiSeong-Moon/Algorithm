#include<iostream>

using namespace std;

class Node {
public:
	char data;
	Node* pre=nullptr;
	Node* next=nullptr;
};//��带 ����� ���� ���� ó���� blank���(���� ����:ptr->next��ġ�� �� ��� ����, ���� ����: ptr���� �� ptr=ptr->pre�ϱ� ���� ���� ó�� blank��� ���� �׷��� ���� ���԰� ������ ���� ����)
//< > - �� blank�� �� �ƴҶ� �׸��� �յ� ��� ���翩�θ� �������� �б� ���� �������� ���� ó���� blank�� ptr�̵� �� ������� ���
int main(void) {
	int test;
	cin >> test;
	for (int T = 0; T < test+1; T++) {
		char a;
		Node blank;
		Node* ptr = &blank;
		while (1) {
			scanf("%c",&a);
			if (a == '\n')
				break;
			if (ptr == &blank) {
				if (a == '-' || a=='<') {
					continue;
				}
				else if (a == '>') {
					if (ptr->next == nullptr)
						continue;
					else
					{
						ptr = ptr->next;
					}
				}
				else {
					if (ptr->next == nullptr) {
						Node* new_node=new Node();	new_node->data = a;	new_node->pre = &blank;
						ptr = new_node;
						blank.next = new_node;
					}
					else {
						Node* new_node = new Node();	new_node->data = a;
						new_node->next = ptr->next;	new_node->pre = &blank;
						new_node->next->pre = new_node;
						blank.next = new_node;
						ptr = new_node;
					}
				}
			}
			else {
				if (a == '-') {
					if (ptr->pre == nullptr) {
						continue;
					}
					else {
						ptr = ptr->pre;
						Node* delete_node = ptr->next;
						ptr->next = delete_node->next;
						if(delete_node->next!=nullptr)
							delete_node->next->pre = ptr;
						free(delete_node);
					}
				}
				else if (a == '>')
				{
					if (ptr->next == nullptr) {
						continue;
					}
					else {
						ptr = ptr->next;
					}
				}
				else if (a == '<')
				{
					if (ptr->pre == nullptr) {
						continue;
					}
					else {
						ptr = ptr->pre;
					}
				}
				else {
					Node* new_node = new Node();	new_node->data = a;	new_node->next = ptr->next;	new_node->pre = ptr;
					if (ptr->next != nullptr)
						ptr->next->pre = new_node;
					ptr->next = new_node;
					ptr = ptr->next;
				}
			}
		}
		if (T == 0)
			continue;
		while (ptr != &blank) {
			ptr = ptr->pre;
		}
		while (ptr->next != nullptr) {
			printf("%c", ptr->next->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
	return 0;
}