struct ListNode* rotateRight(struct ListNode* head, int k) 
{
	if(head==NULL) //����Ϊ��
		return NULL;
	if(k==0 || head->next==NULL) //k=0��������ֻ��һ���ڵ�
		return head;
	struct ListNode* ptr1=head��
	struct ListNode* ptr2=head;
	int i=1;
	int length=0;
	while(ptr1)//��������ĳ���
	{
    	length++;
    	ptr1=ptr1->next;
	}
	ptr1=head;
	if(k>length)//k�ȳ���len��ʱ��ȡģ
		k = k%length;
	if(k==length)
		return head;
	for(i=1;i<=k;i++)
	{
		if(ptr2->next==NULL)
			return head;
		ptr2=ptr2->next;
	}
    while(ptr2->next!=NULL)
	{
        ptr2=ptr2->next;
        ptr1=ptr1->next;
    }
    ptr2->next=head;
	head = ptr1->next;
	ptr1->next=NULL; 
	return head;
}