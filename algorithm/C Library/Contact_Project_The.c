#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 
typedef struct _student{
	char* id;
	char* name;
	char* numberphone;
	char* datetime;
}BAN;
void InputString(const char * pTitle,char **ppName)
{
	char temp[1024];
	printf("%s: ",pTitle);
	fflush(stdin);
	gets(temp);
	*ppName= (char *)malloc(strlen(temp)+1);
	strcpy(*ppName,temp);
}

void InputMemberData(BAN *pMember)
{
	InputString("ID",&pMember->id);
	InputString("Name",&pMember->name);
	InputString("NumberPhone",&pMember->numberphone);
	InputString("Date",&pMember->datetime);
}

void InputMember(BAN MemArray[],int *piIndex,int iArraySize)
{
if(*piIndex >= iArraySize)
{
	printf("Can't Add New Member, Buffer is full\n");
	return;
}	
	InputMemberData(&MemArray[*piIndex]);
		++(*piIndex);
}

void PrintMemberData(BAN *b)
{
	printf("\nID : %s",b->id);
	printf("\nName : %s",b->name);
	printf("\nNumberPhone : %s",b->numberphone);
	printf("\nDatetime : %s",b->datetime);
}
//
void PrintAll(BAN MemArray[],int iIndex)
{
for(int i=0; i<iIndex;++i)
{
	PrintMemberData(&MemArray[i]);
}
}
//
int Search_name(BAN ban[],int *size)
{
	char name[30];
	printf("\nInput Name that you wanna searching: ");
	fflush(stdin);
	gets(name);
	for(int i=0;i<*size;i++)
	{
		if(strcmp(name,ban[i].name) == 0)
		{
			return i;
			break;
		}
	}
		return -1;
}
//searching index
int Search_index(BAN ban[],int size)
{
	char id[30];
	printf("\nInput id that you wanna searching: \n");
	fflush(stdin);
	gets(id);
	for(int i=0;i<size;++i)
	{
		if(strcmp(ban[i].id,id)==0)
		{
			return i;
		}
	}
		return -1;
}
void Searching_by_name(BAN ban[],int *size)
{
				int Result = Search_name(ban,size);
				if(Result!=-1){
					PrintMemberData(&(ban[Result]));
				}else{
						printf("Not Found!!!");
					}
}
void Searching_by_id(BAN ban[],int size)
{
	int Result = Search_index(ban,size);
	if(Result!=-1){
			PrintMemberData(&(ban[Result]));
	}else{
			printf("Not Found!!!");
	}
}
void Search(BAN MemArray[],int iIndex)
{
	char Name[1024];
	printf("Name : ");
	gets(Name);
	int iSearch= Search_name(MemArray,&iIndex);
if(iSearch!=-1){
	PrintMemberData(&MemArray[iSearch]);
}else
{
	printf("Not Found");
}
}
void FreeMemberData(BAN *pMember)
{
	free(pMember->id);
	free(pMember->name);
	free(pMember->numberphone);
	free(pMember->datetime);
}
void DeleteAt(BAN MemberArray[],int * piIndex,int iSearch)
{
	if(*piIndex == 0 ||(iSearch<0 && iSearch<*piIndex))
	{
		printf("you should delete after index fits");
	}
	FreeMemberData(&MemberArray[iSearch]);
//MoveMemberData();
	(&MemberArray[iSearch],&MemberArray[iSearch+1],sizeof(BAN)*(*piIndex-iSearch-1));
	--(*piIndex);
}
//void MoveMemberData();
//Delete Index change need to use address &iIndex
void Delete_me(BAN MemberArray[],int * piIndex)//Delete func to delete member
{
	for(int i=0;i<*piIndex;i++){
		int iSearch = Search_name(MemberArray,piIndex);
		if(iSearch != -1){
			//PrintMemberData(&MemberArray[i]);
			DeleteAt(MemberArray,piIndex,iSearch);
		}else
		{
			printf("NOT FOUND!!!");
		}
	}
	PrintAll(MemberArray,*piIndex);
}
void DeleteAll(BAN ban[], int *iIndex)
{
        for (int i = 0; i < *iIndex; i++)
        {
                DeleteAt(ban, iIndex, i);
        }
        *iIndex = 0;
}
int compare_string(void *a,void *b){
	int result = 0;
	const char *ca = (const char *)a;
	const char *cb = (const char *)b;
	if(strcmp(ca,cb) > 0)
	{
		result = 1;
	}
		return result;
//return (a[0] - b[0]);//-1
}

//sap xep theo insertionsort
void insertSort(BAN a[],int size)
{
	int i,j;
	for(i=1;i<size;i++){
			BAN temp = a[i];
			j=i-1;
			while(j>=0 && strcmp(a[j].name,temp.name)>0){
				a[j+1] = a[j];
				//strcpy(a[j+1].name,a[j].name);
				j--;
			}
			a[j+1] = temp;
			//strcpy(a[j+1].name,temp.name);
	}
}

//sap xep theo shellsort
void sort_by_shell(BAN ban[],int size)
{
	int i,j,interrup;
	BAN temp;
	for(interrup=size/2;interrup>0;interrup=interrup/2){
		for(i=0;i<size;i=i+interrup){
			temp=ban[i];
			//strcpy(temp.numberphone,ban[i].numberphone);
			for(j=i;j>0 && compare_string(ban[j-interrup].numberphone,ban[j].numberphone)==1;j--){
				//strcpy(ban[j].numberphone,ban[j-interrup].numberphone);
				ban[j] = ban[j-interrup];
			}
			ban[j] = temp;
			//strcpy(ban[j].numberphone,temp.numberphone);
		}
	}
	PrintAll(ban,size);
}
//////mergesort
void mer_sort(BAN ar[],int start,int end)
{
	int mid;
	int i,j,k;
	mid = (start+end)/2;
	i = start;
	j = mid+1;
	k=0;
	BAN temp[50]; 
	while(i<=mid && j<=end){
		if(compare_string(ar[j].id,ar[i].id)==1){
			temp[k] = ar[i];
			i++;
		}else{
			temp[k] = ar[j];
			j++;
		}
		k++;
	}
	while(i<=mid){temp[k++]=ar[i++]; }
	while(j<=end){temp[k++]=ar[j++]; }
	//copy
	j = start;
	for(i=0;i<k;i++){
		ar[j++] = temp[i];
	}
}
void Merger_Sort_vision(BAN a[],int start,int end)
{
	int mid = (start+end)/2;
	if(start < end){
		Merger_Sort_vision(a,start,mid);
		Merger_Sort_vision(a,mid+1,end);
		mer_sort(a,start,end);
	}
}
void   Swap_2(BAN *CT1, BAN *CT2)
{
        BAN temp;
        temp = *CT1;
        *CT1 = *CT2;
        *CT2 = temp;
}
 
int Partition(BAN data[], int first, int last)
{
        int i,j;
		BAN	pivot = data[last];
		i = first-1;
	for(j=first;j<last;j++){
		i++;
		if(strcmp((data[j].datetime),(pivot.datetime)) > 0){
			Swap_2(data+i,&pivot);
		}
		j++;
	}
	Swap_2(data+i+1,&pivot);
	return i+1;
}
 
int QuickSort(BAN CT[], int first, int last){
        int     mid;
        if (first < last){
                mid = Partition(CT, first, last);       // <- very important
                QuickSort(CT, first, mid - 1);  // left seg array
                QuickSort(CT, mid, last);       // right seg array
        }
        return 0;
}

//search  
void Modify(BAN ban[],int size)
{
	int iSearch = Search_name(ban,&size);
	if(iSearch!=-1)
	{ 
		FreeMemberData(&ban[iSearch]);
		InputMemberData(&ban[iSearch]);
	}else
	{
		printf("Not Found");
	}
}
void Edit(BAN ban[],int size)
{
	int chon;
	printf("you want edit information\n");
	scanf("%d",&chon);
	int iSearch = Search_name(ban,&size);
	if(iSearch!=-1)
	{ 
		switch(chon){
		case 1:
			char id[50];
			printf("\nInput ID : ");
			fflush(stdin);
			gets(id);
			strcpy(ban->id,id);
			break;
		case 2:
			char name[50];
			printf("\nInput Name : ");
			fflush(stdin);
			gets(name);
			strcpy(ban->name,name);
			break;
		case 3:
			char numberphone[50];
			printf("\nInput Name : ");
			fflush(stdin);
			gets(numberphone);
			strcpy(ban->numberphone,numberphone);
			break;
		case 4:
			char date[50];
			printf("\nInput Name : ");
			fflush(stdin);
			gets(date);
			strcpy(ban->datetime,date);
			break;
		}
	}else
	{
		printf("Not Found");
	}
}

//deleteall
void DeleteAll_2(BAN *ban)
{
	delete[]ban;
}

void save(BAN sv[],int size){
	FILE *output = fopen("ds.txt", "a+");
	for(int i=0;i<size;i++)
	{
		fprintf(output,"%s\t%s\t%s\t%s\t\n",(sv+i)->id,(sv+i)->name,(sv+i)->numberphone,(sv+i)->datetime);
	}
	  fclose(output);
}
void ReadFile_1(BAN sv[],int i,char *name)
{
	i=0;
	FILE*pRead;
	pRead = fopen(name, "r");
      if ( pRead != NULL ) {
         while ( !feof(pRead) ) {
			 fscanf(pRead, "%s %s %s %s",sv[i].id, sv[i].name,sv[i].numberphone,sv[i].datetime);
           if ( !feof(pRead) )
              printf("%s %s %s %s\n",sv[i].id, sv[i].name,sv[i].numberphone,sv[i].datetime);
		  
         } //end loop
		  ++i;
}
}
void ReadFile(BAN *sv,int &size)
{
	FILE *f = fopen("ds.txt", "rb"); //mở file để đọc  
    fscanf(f, "%d", &size);              //đọc số phần tử của mảng và lưu vào n
    for (int i = 0; i < size; i++)       //đọc lần lượt từng giá trị của mảng
		fscanf(f,"%s\t%s\t%s\t%s\t\n",((sv+i)->id),((sv+i)->name),((sv+i)->numberphone),((sv+i)->datetime));
    fclose(f); 
    printf("\nData Array : \n");      //hiển thị mảng
    for (int i = 0; i < size; i++)
		printf("%s\t%s\t%s\t%s\t\n",(sv+i)->id,(sv+i)->name,(sv+i)->numberphone,(sv+i)->datetime);
}

void show_menu_main()
{
	  printf("\n			      MENU Main program");
	  printf("\n   	  	    ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
	  printf("\n   		    º 1.Create infomation user phone number  º");
	  printf("\n   		    º 2.Show List infomation that you create º");
	  printf("\n   		    º 3.Search                               º");
	  printf("\n   		    º 4.MODIFY                               º");
	  printf("\n   		    º 5.DELETE                               º");
	  printf("\n   		    º 6.DELETE ALL                           º");
	  printf("\n		    º 7.  SORT ALL INFORMATION		     º");
	  printf("\n		    º 8.SAVE TO FILE			     º");
	  printf("\n		    º 9.READ FROM FILE			     º");
	  printf("\n		    º 10.EXITS				     º");
	  printf("\n		    º 11.EDIT				     º");
	  printf("\n   		    ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
	  printf("\n");
}
void show_list_delete()
{
	printf("\n			      MENU DELETE");
	  printf("\n   	  	    ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
	  printf("\n   		    º 1.Delete by Name			     º");
	  //printf("\n   		    º 2.Delete by ID			     º");
	  printf("\n   		    ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
	  printf("\n");
}
void show_menu_sort()
{
	printf("\n			      MENU SORT");
	  printf("\n   	  	    ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
	  printf("\n   		    º 1.SORT BY NAME			     º");
	  printf("\n   		    º 2.SORT BY BY PHONENUMBER		     º");
	  printf("\n   		    º 3.SORT BY BY DATE			     º");
	  printf("\n   		    º 4.SORT BY BY ID			     º");
	  printf("\n   		    ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
	  printf("\n");
}
void show_menu_EDIT()
{
	printf("\n			      MENU EDIT");
	  printf("\n   	  	    ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
	  printf("\n   		    º 1.EDIT BY ID			     º");
	  printf("\n   		    º 2.EDIT BY BY NAME			     º");
	  printf("\n   		    º 3.EDIT BY BY NUMBERPHONE		     º");
	  printf("\n   		    º 4.EDIT BY BY DATE			     º");
	  printf("\n   		    ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
	  printf("\n");
}
void Show_Create()
{
	printf("\n			      CREATE DATA FOR USERS");
	  printf("\n   	  	    ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
	  printf("\n   		    º 1.CREATE DATA			     º");
	  printf("\n   		    ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
	  printf("\n");
}
void Show_Output()
{
	printf("\n			      ALL DATA FOR USERS");
	  printf("\n   	  	    ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
	  printf("\n   		    º 2.ALL INFORMATION OF USER		     º");
	  printf("\n   		    ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
	  printf("\n");
}
void Show_Searching()
{
	printf("\n			      SEARCHING DATA FOR USERS");
	  printf("\n   	  	    ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
	  printf("\n   		    º 1.SEARCHING BY NAME		     º");
	  printf("\n   		    º 2.SEARCHING BY ID			     º");
	  printf("\n   		    ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
	  printf("\n");
}
void Show_Modify()
{
	printf("\n			      MODIFY DATA FOR USERS");
	  printf("\n   	  	    ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
	  printf("\n   		    º 4.MODIFY DATA 			     º");
	  printf("\n   		    ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
	  printf("\n");
}
void Show_delete_All()
{
	printf("\n			      DELETE ALL DATA FOR USERS");
	  printf("\n   	  	    ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
	  printf("\n   		    º 1.YES,I WILL DELET ALL  		     º");
	  printf("\n		    º  2. NO,I COMEBACK MENU MAIN  	     º");
	  printf("\n   		    ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
	  printf("\n");
}
void Show_soLuong_users()
{
	printf("			      INPUT MANY USERS");
	  printf("\n   	  	    ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
	  printf("\n   		    º 1.INPUT MANY DATA 		     º");
	  printf("\n   		    ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
	  printf("\n");
}
void Show_data_read_file()
{
	printf("\n			      INFORMATION FROM FILE ");
	  printf("\n   	  	    ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
	  printf("\n   		    º 9.LIST USERS 			     º");
	  printf("\n   		    ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
	  printf("\n");
}

int main_2()
{
	return 0;
}
int main()
{
	//show_menu_main();
	BAN b[10];
	int iIndex =0;//No Data
	int choice;
label:	show_menu_main();
	printf("Input that you want choice : \n");
	scanf("%d",&choice);
	switch(choice){
	case 1:
		{
		Show_Create();
		InputMember(b,&iIndex,
			sizeof(b)/sizeof(b[0]));// Input run pointer point to iIndex address, get value iIndex ++
		goto label;
		break;
		}
	case 2:
		{
			Show_Output();
			PrintAll(b,iIndex);
			goto label;
			break;
		}
	case 3:
		Show_Searching();
		int chon;
		printf("Input choice that you searching!!!\n");
		scanf("%d",&chon);
		switch(chon){
		case 1:
			Searching_by_name(b,&iIndex);
			goto label;
			break;
		case 2:
			Searching_by_id(b,iIndex);
			goto label;
			break;
		}
	case 4:
		Show_Modify();
		Modify(b,iIndex);
		goto label;
		break;
	case 11:
		show_menu_EDIT();
		Edit(b,iIndex);
		goto label;
		break;
	case 5:
		show_list_delete();		
		//Delete(b,&iIndex);
		Delete_me(b,&iIndex);
		//PrintAll(b,iIndex);
		goto label;
		break;
	case 6:
		Show_delete_All();
		int de;
		printf("YOU WANT CHOICE ");
		scanf("%d",&de);
		switch(de){
		case 1:
			DeleteAll(b,&iIndex);
			goto label;
			break;
		case 2:
			goto label;
			break;
		}
	case 7:
		{
		show_menu_sort();
		int sort;
		printf("Please Input choice to sort data\n");
		scanf("%d",&sort);
		switch(sort){
		case 1:
			insertSort(b,iIndex);
			PrintAll(b,iIndex);
			goto label;
			break;
		case 2:
			sort_by_shell(b,iIndex);
			goto label;
			break;
		case 3:
			QuickSort(b,0,iIndex-1);
			PrintAll(b,iIndex);
			goto label;
			break;
		case 4:
			Merger_Sort_vision(b,0,iIndex-1);
			PrintAll(b,iIndex);
			goto label;
			break;
		}
		}
		break;
	case 8:
			save(b,iIndex);
			goto label;
		break;
	case 9:
		Show_data_read_file();
		ReadFile_1(b,iIndex,"ds.txt");
		goto label;
		break;
	case 10:
		exit(0);
		break;
	}
	return 0;
}