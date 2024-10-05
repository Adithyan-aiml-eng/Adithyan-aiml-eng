#include<iostream>
int size;
struct node{
    int data;
    struct node *previous,*next;
}*header,*tail;
void creation_linked_list(){
    std::cout<<"Enter the size of linked list: ";
    std::cin>>size;
    struct node* newnode;
    newnode=new node;
    if((newnode==NULL)||(size<=0)){
        std::cout<<"Error: invalid size"<<std::endl;
    }
    else {
        header=newnode;
        tail=newnode;
        newnode->previous=NULL;
        newnode->next=NULL;
        std::cout<<"Enter the data: ";
        std::cin>>newnode->data;
        for(int i=1;i<size;i++){
            newnode=new node;
            if((newnode==NULL)){
                std::cout<<"Error: unable to allocate memory"<<std::endl;
            }
            else{
                tail->next=newnode;
                newnode->previous=tail;
                std::cout<<"Enter the data: ";
                std::cin>>newnode->data;
                newnode->next=NULL;
                tail=newnode;
            }
         
        }
    }
}
void display(){
    if(header==NULL){
        std::cout<<"link is empty"<<std::endl;
    }
    else{
        node *ptr;
        ptr=header;
        std::cout<<"Entered element are:\n";
        while (ptr!=NULL)
        {
            std::cout<<ptr->data<<" ";
            ptr=ptr->next;
        }std::cout<<"\n";
        
    }
}
void insertion(){
    int position;
    std::cout<<"Enter in which position you have to insert: ";
    std::cin>>position;
    node *newnode;
    newnode=new node;
    if((position<=0)||(position>size+1)){
        std::cout<<"Error: invalid position"<<std::endl;
    }
    else if(position==1){
        newnode->next=header;
        header->previous=newnode;
        std::cout<<"Enter the data: ";
        std::cin>>newnode->data;
        newnode->previous=NULL;
        header=newnode;
        size++;
    }
    else if(position==size+1){
        tail->next=newnode;
        newnode->previous=tail;
        std::cout<<"Enter the data: ";
        std::cin>>newnode->data;
        newnode->next=NULL;
        tail=newnode;
        size++;
    }
    else{
        int count=1;
        node *ptr,*temp;
        ptr=header;
        while((ptr!=NULL)&&(count<position-1)){
            ptr=ptr->next;
            count++;
        }
        temp=ptr->next;
        newnode->next=temp;
        temp->previous=newnode;
        ptr->next=newnode;
        newnode->previous=ptr;
        std::cout<<"Enter the data: ";
        std::cin>>newnode->data;
        size++;
    }
}
void deletion(){
   int position;
   node *temp,*temp1,*temp2;
   node *newnode=new node;
   std::cout<<"Enter in which position you have to delete: ";
   std::cin>>position;
    if((position<=0)||(position>size+1)){
        std::cout<<"Error: invalid position"<<std::endl;
    }
    else if(position==1){
        temp=header;
        header=header->next;
        temp->next=NULL;
        delete(temp);
        size--;
    }
    else if(position==size){
        temp=tail;
        tail=tail->previous;
        tail->next=NULL;
        temp->previous=NULL;
        delete(temp);
        size--;
    }
    else{
        int count=1;
        temp=header;
        while((header!=NULL)&&(count<position-1)){
            temp=temp->next;
            count++;
        }
        temp1=temp->next;
        temp2=temp1->next;
        temp->next=temp2;
        temp2->previous=temp;
        temp1->next=NULL;
        temp1->previous=NULL;
        delete(temp1);
        size--;
    }

}


int main(){
    std::cout<<"You have to create a doubly linked list to insert and delete"<<std::endl;
    creation_linked_list();
    display();
    int select;
    while(true){
        std::cout<<"Enter 1 for insertion, 2 for deletion: ";
        std::cin>>select;
        switch(select){
            case 1:
            insertion();
            display();
            break;
            case 2:
            deletion();
            display();
            break;  
        }
    }
    return 1;
}