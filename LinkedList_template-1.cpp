// Michelle Aguilar
// CWID: 884875618

#include<iostream>
#include<memory>
#include<vector>
#include<string>

// Write template class Tab here
template <typename T>
class Tab {
    public:
    // Created the two pointers.
    Tab* next;
    Tab* prev;

    Tab(const std::string& url, const std::string& name, const T& memory)
       : url(url), name(name), memory(memory), prev(nullptr), next(nullptr) {}
    
    ~Tab() {}

    std::string getUrl() const { return url; }
    std::string getName() const {return name;}
    T getMemory() const {return memory;}

    private:
    // Created the three values.
    std::string url;
    std::string name;
    T memory;

};


// Write template class Browser here
template <typename T>
class Browser {
    public:
    Browser() : head(nullptr), tail(nullptr), current(nullptr) {}

    void addNewTab(const std::string& url, const std::string& name, const T& memory) {
        Tab<T>* newTab = new Tab(url, name, memory);
        if (!head) {
            head = tail = current = newTab;
        } else {
            tail->next = newTab;
            newTab->prev = tail;
            tail = newTab;
            current = newTab;
        }
    }

    void switchToPrevTab() {
        if(current && current->prev) {
            current = current->prev;
            std::cout << "Switch to previous tab =\n";
            std::cout << current->getUrl;
            std::cout << current->getName;
            std::cout << current->getMemory;
        } else {
            std::cout << "Switch to previous tab =\n";
            std::cout << "No previous tab\n";
        }
    }

    void switchToNextTab() {
        if (current && current->next) {
            current = current->next;
            std::cout << "Switch to Next tab =\n";
            std::cout << current->getUrl;
            std::cout << current->getName;
            std::cout << current->getMemory;
        } else {
            std::cout << "Switch to Next tab =\n";
            std::cout << "No Next tab\n";
        }
    }

    private:
    Tab<T>* head;
    Tab<T>* tail;
    Tab<T>* current;
};

//Add display method in Browser template class 
    /*void display(){
            auto curr = head;
            std::cout<<"Browser tab list = "<<std::endl;
            while(curr){
                std::cout<<"| "<<curr->name<<"  x|-->";
                curr = curr->next;
            }
            std::cout<<std::endl;
            std::cout<<std::endl;
        }
    */
int main(){

    /*Browser<double> b1;
    b1.addNewTab("https://www.google.com","Google",23.45);
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    std::cout<<"Switch to Next tab = "<<std::endl;
    b1.switchToNextTab();
    b1.addNewTab("https://www.youtube.com","YouTube",56);
    b1.bookmarkCurrent();
    b1.display();
    b1.addNewTab("https://www.geeksforgeeks.com","GeeksForGeeks",45.78);
    b1.bookmarkCurrent();
    b1.addNewTab("https://chat.openai.com","ChatGPT",129);
    b1.addNewTab("https://linkedin.com","LinkedIn",410);
    b1.bookmarkCurrent();
    b1.addNewTab("https://github.com","Github",110);
    b1.addNewTab("https://kaggle.com","Kaggle",310);
    b1.bookmarkCurrent();
    b1.display();
    std::cout<<"Total memory consumption = "<<b1.total_memory()<<"MB"<<std::endl;
    b1.showBookmarkTab();
    b1.moveCurrentToFirst();
    b1.display();
    b1.deleteTab();
    b1.display();
    std::cout<<"Switch to next tab = "<<std::endl;
    b1.switchToNextTab();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    b1.closeCurrentTab();
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    b1.closeCurrentTab();
    b1.display();
    b1.showBookmarkTab();
    std::cout<<"Total Memory Consumption = "<<b1.total_memory()<<"MB"<<std::endl;
    b1.deleteTab();
    b1.display();
    b1.addNewTab("https://docs.google.com/","Google Docs",102.34);
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    b1.bookmarkCurrent();
    b1.showBookmarkTab();
    b1.total_memory();
    b1.deleteTab();
    b1.display();*/
    return 0;
}