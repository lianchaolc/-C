#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <windows.h> // 必须加这个头文件
using namespace std;

// 学生结构体
struct Student {
    int id;
    string name;
    int age;
};

vector<Student> students;

void addStudent() {
    Student s;
    cout << "\n输入学生ID: ";
    cin >> s.id;
    cout << "输入学生姓名: ";
    cin >> s.name;
    cout << "输入学生年龄: ";
    cin >> s.age;
    students.push_back(s);
    cout << "添加成功！" << endl;
}

void deleteStudent() {
    int id;
    cout << "\n输入要删除的学生ID: ";
    cin >> id;
    
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            cout << "删除成功！" << endl;
            return;
        }
    }
    cout << "未找到该学生！" << endl;
}

void updateStudent() {
    int id;
    cout << "\n输入要修改的学生ID: ";
    cin >> id;
    
    for (auto& s : students) {
        if (s.id == id) {
            cout << "输入新姓名: ";
            cin >> s.name;
            cout << "输入新年龄: ";
            cin >> s.age;
            cout << "修改成功！" << endl;
            return;
        }
    }
    cout << "未找到该学生！" << endl;
}

void queryStudents() {
    cout << "\n学生列表: " << endl;
    cout << "ID\t姓名\t年龄" << endl;
    cout << "----------------------" << endl;
    for (const auto& s : students) {
        cout << s.id << "\t" << s.name << "\t" << s.age << endl;
    }
}

int main() {
    // 核心两行：强制控制台使用UTF8编码
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int choice;
    while (true) {
        cout << "\n=====学生管理系统=====";
        cout << "\n1. 添加学生";
        cout << "\n2. 删除学生";
        cout << "\n3. 修改学生";
        cout << "\n4. 查询学生";
        cout << "\n5. 退出";
        cout << "\n请选择操作: ";
        cin >> choice;
        
        switch(choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: updateStudent(); break;
            case 4: queryStudents(); break;
            case 5: 
                cout << "程序即将退出，按回车键关闭窗口..." << endl;
                system("pause");
                return 0;
            default: cout << "无效选择！" << endl;
        }
    }
}