#include<iostream>
#include<string>
using namespace std;

class list
{
public:
    int val;
    list *next;
    list(int value) : val(value), next(nullptr) {}
};
void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

void reverse_string(string& s)
{
    int left = 0, right = s.size() - 1;
    while(left <= right)
    {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}
// Function to insert at end
void insert_end(list* &head, int value)
{
    if(head == nullptr)
    {
        head = new list(value);
        return;
    }

    list* temp = head;
    while(temp->next != nullptr)
        temp = temp->next;

    temp->next = new list(value);
}

string add_two_numbers(const string &a, const string &b)
{
    list* num1 = nullptr;
    list* num2 = nullptr;

    // Put digits of a in reverse
    for(int i = a.size() - 1; i >= 0; i--)
        insert_end(num1, a[i] - '0');

    // Put digits of b in reverse
    for(int i = b.size() - 1; i >= 0; i--)
        insert_end(num2, b[i] - '0');

    list* result = nullptr;
    int carry = 0;

    list* p1 = num1;
    list* p2 = num2;

    while(p1 != nullptr || p2 != nullptr || carry)
    {
        int digit1 = (p1 != nullptr) ? p1->val : 0;
        int digit2 = (p2 != nullptr) ? p2->val : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;

        insert_end(result, sum % 10);

        if(p1) p1 = p1->next;
        if(p2) p2 = p2->next;
    }

    // Convert result list back to string (reverse again)
    string ans;
    list* temp = result;

    while(temp != nullptr)
    {
        ans += static_cast<char>(temp->val + '0') ;  // prepend
        temp = temp->next;
    }
    reverse_string(ans);
    return ans;
}

int main()
{
    string num1, num2;

    cout << "Enter first number : ";
    cin >> num1;

    cout << "Enter second number : ";
    cin >> num2;

    string result = add_two_numbers(num1, num2);
    cout << "Sum = " << result << endl;
}
