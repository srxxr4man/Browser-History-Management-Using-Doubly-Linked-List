
#include <iostream>
#include <string>
using namespace std;

struct Page{
    Page *right;
    Page *left;
    int id;
    string url;
    string title;
};

Page *current=NULL;

void getPageDetails(int &id,string &url,string &title){
    cout<<"Enter the ID: ";
    cin>>id;
    cout<<"Enter the URL: ";
    cin>>url;
    cin.ignore();
    cout<<"Enter the Title: ";
    getline(cin,title);
}

bool checkID(Page *head,int id){
    Page *temp=head;

    while(temp!=NULL){
        if(temp->id==id){
            return true;
        }
        temp=temp->right;
    }

    return false;
}

void addFront(int id,string url,string title,Page *&head){
    if(checkID(head,id)){
        cout<<"Page ID Already Exists"<<endl;
        return;
    }

    Page *newPage=new Page();
    newPage->id=id;
    newPage->url=url;
    newPage->title=title;
    newPage->left=NULL;
    newPage->right=NULL;

    if(head==NULL){
        head=newPage;
        current=newPage;
        cout<<"Page Added Successfully"<<endl;
        return;
    }

    newPage->right=head;
    head->left=newPage;
    head=newPage;
    cout<<"Page Added Successfully to the Front"<<endl;
}

void addBack(int id,string url,string title,Page *&head){
    if(checkID(head,id)){
        cout<<"Page ID Already Exists"<<endl;
        return;
    }

    Page *newPage=new Page();
    newPage->id=id;
    newPage->url=url;
    newPage->title=title;
    newPage->left=NULL;
    newPage->right=NULL;

    if(head==NULL){
        head=newPage;
        current=newPage;
        cout<<"Page Added Successfully"<<endl;
        return;
    }

    Page *temp=head;
    while(temp->right!=NULL){
        temp=temp->right;
    }

    temp->right=newPage;
    newPage->left=temp;
    cout<<"Page Added Successfully to the Back"<<endl;
}

void addSpecific(int id,string url,string title,int afterId,Page *&head){
    if(checkID(head,id)){
        cout<<"Page ID Already Exists"<<endl;
        return;
    }

    if(head==NULL){
        cout<<"List is Empty"<<endl;
        return;
    }

    Page *temp=head;
    while(temp!=NULL && temp->id!=afterId){
        temp=temp->right;
    }

    if(temp==NULL){
        cout<<"Page with ID "<<afterId<<" NOT Found"<<endl;
        return;
    }

    Page *newPage=new Page();
    newPage->id=id;
    newPage->url=url;
    newPage->title=title;
    newPage->left=temp;
    newPage->right=temp->right;

    if(temp->right!=NULL){
        temp->right->left=newPage;
    }

    temp->right=newPage;

    cout<<"Page Added Successfully after ID "<<afterId<<endl;
}

void displayForward(Page *head){
    if(head==NULL){
        cout<<"History is Empty"<<endl;
        return;
    }

    Page *temp=head;
    cout<<"\nFORWARD HISTORY\n"<<endl;
    cout<<"NULL"<<" -> ";

    while(temp!=NULL){
        cout<<"| ID: "<<temp->id<<" | URL: "<<temp->url<<" | Title: "<<temp->title<<" | "<<" -> ";
        temp=temp->right;
    }

    cout<<"NULL"<<endl;
}

void displayBackward(Page *head){
    if(head==NULL){
        cout<<"History is Empty"<<endl;
        return;
    }

    Page *temp=head;

    while(temp->right!=NULL){
        temp=temp->right;
    }

    cout<<"\nBACKWARD HISTORY\n"<<endl;
    cout<<"NULL"<<" -> ";

    while(temp!=NULL){
        cout<<"| ID: "<<temp->id<<" | URL: "<<temp->url<<" | Title: "<<temp->title<<" | "<<" -> ";
        temp=temp->left;
    }

    cout<<"NULL"<<endl;
}

void deleteFront(Page *&head){
    if(head==NULL){
        cout<<"History is Empty"<<endl;
        return;
    }

    Page *temp=head;

    if(current==head){
        current=head->right;
    }

    head=head->right;

    if(head!=NULL){
        head->left=NULL;
    }

    delete temp;
    cout<<"Page deleted from the front of the history"<<endl;
}

void deleteBack(Page *&head){
    if(head==NULL){
        cout<<"History is Empty"<<endl;
        return;
    }

    Page *temp=head;

    while(temp->right!=NULL){
        temp=temp->right;
    }

    if(current==temp){
        current=temp->left;
    }

    if(temp->left!=NULL){
        temp->left->right=NULL;
    }
    else{
        head=NULL;
    }

    delete temp;
    cout<<"Page deleted from the back of the history"<<endl;
}

void deleteSpecific(Page *&head,int deleteId){
    if(head==NULL){
        cout<<"History is Empty"<<endl;
        return;
    }

    Page *temp=head;

    while(temp!=NULL && temp->id!=deleteId){
        temp=temp->right;
    }

    if(temp==NULL){
        cout<<"Page ID "<<deleteId<<" NOT Found in the History"<<endl;
        return;
    }

    if(current==temp){
        current=temp->right;

        if(current==NULL){
            current=temp->left;
        }
    }

    if(temp->left!=NULL){
        temp->left->right=temp->right;
    }
    else{
        head=temp->right;
    }

    if(temp->right!=NULL){
        temp->right->left=temp->left;
    }

    delete temp;
    cout<<"Page ID "<<deleteId<<" deleted from the history"<<endl;
}

void searchPage(Page *head,int searchId){
    Page *temp=head;

    while(temp!=NULL){
        if(temp->id==searchId){
            cout<<"\nPAGE FOUND"<<endl;
            cout<<"ID: "<<temp->id<<endl;
            cout<<"URL: "<<temp->url<<endl;
            cout<<"Title: "<<temp->title<<endl;
            return;
        }

        temp=temp->right;
    }

    cout<<"Page ID "<<searchId<<" NOT Found"<<endl;
}

void previousPage(){
    if(current==NULL){
        cout<<"No Page Available"<<endl;
        return;
    }

    if(current->left==NULL){
        cout<<"No Previous Page Available"<<endl;
        return;
    }

    current=current->left;

    cout<<"\nPrevious Page Opened"<<endl;
    cout<<"ID: "<<current->id<<endl;
    cout<<"URL: "<<current->url<<endl;
    cout<<"Title: "<<current->title<<endl;
}

void nextPage(){
    if(current==NULL){
        cout<<"No Page Available"<<endl;
        return;
    }

    if(current->right==NULL){
        cout<<"No Next Page Available"<<endl;
        return;
    }

    current=current->right;

    cout<<"\nNext Page Opened"<<endl;
    cout<<"ID: "<<current->id<<endl;
    cout<<"URL: "<<current->url<<endl;
    cout<<"Title: "<<current->title<<endl;
}

void displayCurrentPage(){
    if(current==NULL){
        cout<<"No Current Page Available"<<endl;
        return;
    }

    cout<<"\nCURRENT PAGE"<<endl;
    cout<<"ID: "<<current->id<<endl;
    cout<<"URL: "<<current->url<<endl;
    cout<<"Title: "<<current->title<<endl;
}

void countPages(Page *head){
    int count=0;
    Page *temp=head;

    while(temp!=NULL){
        count++;
        temp=temp->right;
    }

    cout<<"Total Pages in History: "<<count<<endl;
}

void freeMemory(Page *&head){
    Page *temp=head;

    while(temp!=NULL){
        Page *next=temp->right;
        delete temp;
        temp=next;
    }

    head=NULL;
    current=NULL;
}

int main(){
    Page *head=NULL;

    int id,choice,afterId,deleteId,searchId;
    string title,url;

    do{
        cout<<"\nBROWSER HISTORY MANAGEMENT"<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"1.  Add Page to the Front"<<endl;
        cout<<"2.  Add Page to the Back"<<endl;
        cout<<"3.  Add Page after a Specific ID"<<endl;
        cout<<"4.  Display Forward History"<<endl;
        cout<<"5.  Display Backward History"<<endl;
        cout<<"6.  Delete Page from the Front"<<endl;
        cout<<"7.  Delete Page from the Back"<<endl;
        cout<<"8.  Delete Page Using Page ID"<<endl;
        cout<<"9.  Search Page Using ID"<<endl;
        cout<<"10. Previous Page"<<endl;
        cout<<"11. Next Page"<<endl;
        cout<<"12. Display Current Page"<<endl;
        cout<<"13. Count Total Pages"<<endl;
        cout<<"14. Exit"<<endl;

        cout<<"Enter the Choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                getPageDetails(id,url,title);
                addFront(id,url,title,head);
                break;

            case 2:
                getPageDetails(id,url,title);
                addBack(id,url,title,head);
                break;

            case 3:
                getPageDetails(id,url,title);
                cout<<"Enter the ID after which you want to add: ";
                cin>>afterId;
                addSpecific(id,url,title,afterId,head);
                break;

            case 4:
                displayForward(head);
                break;

            case 5:
                displayBackward(head);
                break;

            case 6:
                deleteFront(head);
                break;

            case 7:
                deleteBack(head);
                break;

            case 8:
                cout<<"Enter the ID you want Delete: ";
                cin>>deleteId;
                deleteSpecific(head,deleteId);
                break;

            case 9:
                cout<<"Enter the Page ID to Search: ";
                cin>>searchId;
                searchPage(head,searchId);
                break;

            case 10:
                previousPage();
                break;

            case 11:
                nextPage();
                break;

            case 12:
                displayCurrentPage();
                break;

            case 13:
                countPages(head);
                break;

            case 14:
                cout<<"Exiting..."<<endl;
                freeMemory(head);
                break;

            default:
                cout<<"Invalid Choice"<<endl;
                break;
        }

    }while(choice!=14);

    return 0;
}