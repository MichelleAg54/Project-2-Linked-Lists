// Michelle Aguilar
// CWID: 884875618

#include<iostream>
#include<memory>
#include<vector>
#include<string>
#include<algorithm>

// Write template class Tab here
template <typename T>
class Tab {
    public:
    // Created the three values.
    std::string url;
    std::string name;
    T memory;
    // Created the two pointers.
    Tab* next;
    Tab* prev;

    Tab(const std::string& url, const std::string& name, const T& memory)
       : url(url), name(name), memory(memory), prev(nullptr), next(nullptr) {}

};


// Write template class Browser here
template <typename T>
class Browser {
    public:
    Browser() : head(nullptr), tail(nullptr), current(nullptr) {}

    void addNewTab(const std::string& url, const std::string& name, const T& memory) {
        Tab<T>* newTab = new Tab<T>(url, name, memory);
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
            // std::cout << "Switch to previous tab =\n";
            std::cout << current->url << "\n";
            std::cout << current->name << "\n";
            std::cout << current->memory << "\n";
        } else {
            std::cout << "No previous tab\n";
        }
    }

    void switchToNextTab() {
        if (current && current->next) {
            current = current->next;
            // std::cout << "Switch to Next tab =\n";
            std::cout << current->url << "\n";
            std::cout << current->name << "\n";
            std::cout << current->memory << "\n";
        } else {
            std::cout << "No Next tab\n";
        }
    }

    
    
    void closeCurrentTab() {
        if (!current) return;
        
        Tab<T>* tabToDelete = current;
        // std::cout << "Closing tab: " << current->name << " (" << current->url << ")\n";

        if (current == head) head = current->next;
        if (current == tail) tail = current->prev;
        if (current->prev) current->prev->next = current->next;
        if (current->next) current->next->prev = current->prev;
        
        current = (tabToDelete->next) ? tabToDelete->next : tabToDelete->prev;
        delete tabToDelete;

        if (current)
            std::cout << "Now the current tab = " << current->name << "\n";

    }

    void bookmarkCurrent() {
    if (!current) {
        std::cout << "No current tab to bookmark." << "\n";
        return;
    }

    // Create a bookmark pair with the current tab's name and url
    std::pair<std::string, std::string> bookmark = make_pair(current->name, current->url);

    // Check if the bookmark already exists in the bookmarks vector
    if (find(bookmarks.begin(), bookmarks.end(), bookmark) != bookmarks.end()) {
        std::cout << "The bookmark is already added!!" << "\n";
    } else {
        // Add the bookmark if it doesn't exist
        bookmarks.push_back(bookmark);
        // sstd::cout << "Bookmark added: " << current->name << " (" << current->url << ")" << "\n";
    }
}
    

    void showBookmarkTab() {
        std::cout << "Bookmarks:\n";
        for (const auto& bm : bookmarks) {
            std::cout << bm.first << " (" << bm.second << ")" << "\n";
        }
    }

    void moveCurrentToFirst() {
        if (!current || current == head) {
            std::cout << "Current tab is already at the first position or there are no tabs.\n";
            return;
        }

        // Remove current tab from its current position
        if (current->prev) current->prev->next = current->next;
        if (current->next) current->next->prev = current->prev;
        if (current == tail) tail = current->prev;

        // Move current tab to the head
        current->next = head;
        current->prev = nullptr;
        head->prev = current;
        head = current;

        // std::cout << "Moved current tab to the first position: " << current->name << "\n";
    }

    // Calculate the total memory consumed by all tabs
    T total_memory() const {
        T totalMemory = 0;
        Tab<T>* temp = head;
        while (temp) {
            totalMemory += temp->memory;
            temp = temp->next;
        }
        return totalMemory;
    }

    // Delete the tab consuming the highest memory
    void deleteTab() {
        if (!head) {
            std::cout << "No tabs to delete.\n";
            return;
        }

        // Find the tab with the highest memory consumption
        Tab<T>* maxMemoryTab = head;
        Tab<T>* temp = head;
        while (temp) {
            if (temp->memory > maxMemoryTab->memory) {
                maxMemoryTab = temp;
            }
            temp = temp->next;
        }

        // Remove maxMemoryTab from the list
        if (maxMemoryTab->prev) maxMemoryTab->prev->next = maxMemoryTab->next;
        if (maxMemoryTab->next) maxMemoryTab->next->prev = maxMemoryTab->prev;
        if (maxMemoryTab == head) head = maxMemoryTab->next;
        if (maxMemoryTab == tail) tail = maxMemoryTab->prev;

        std::cout << "Deleted element: " << maxMemoryTab->name
             << "with memory size = " << maxMemoryTab->memory << "\n";
        delete maxMemoryTab;
    }
    // Add display method in Browser template class 
    void display(){
            auto curr = head;
            std::cout<<"Browser tab list = \n";
            while(curr){
                std::cout<<"| "<<curr->name<<"  x|-->";
                curr = curr->next;
            }
            std::cout<<std::endl;
            std::cout<<std::endl;
        }

    private:
    Tab<T>* head;
    Tab<T>* tail;
    Tab<T>* current;
    std::vector<std::pair<std::string, std::string>> bookmarks;

};



int main(){

    Browser<double> b1;
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
    b1.display();
    return 0;
}