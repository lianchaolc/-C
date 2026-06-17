#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <windows.h>

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
    printf("\n输入学生ID: ");
    cin >> s.id;
    printf("输入学生姓名: ");
    cin >> s.name;
    printf("输入学生年龄: ");
    cin >> s.age;
    students.push_back(s);
    printf("添加成功！\n");
}

void deleteStudent() {
    int id;
    printf("\n输入要删除的学生ID: ");
    cin >> id;
    
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            printf("删除成功！\n");
            return;
        }
    }
    printf("未找到该学生！\n");
}

void updateStudent() {
    int id;
    printf("\n输入要修改的学生ID: ");
    cin >> id;
    
    for (auto& s : students) {
        if (s.id == id) {
            printf("输入新姓名: ");
            cin >> s.name;
            printf("输入新年龄: ");
            cin >> s.age;
            printf("修改成功！\n");
            return;
        }
    }
    printf("未找到该学生！\n");
}

void queryStudents() {
    printf("\n学生列表:\n");
    printf("%-6s %-10s %s\n", "ID", "姓名", "年龄");
    printf("-----------------------------\n");
    for (const auto& s : students) {
        printf("%-6d %-10s %d\n", s.id, s.name.c_str(), s.age);
    }
}

int main() {
    // 设置控制台UTF8
    // SetConsoleOutputCP(65001);
    // SetConsoleCP(65001);
SetConsoleOutputCP(936);
SetConsoleCP(936);
    int choice;
    while (true) {
        printf("\n=====学生管理系统=====\n");
        printf("1. 添加学生\n");
        printf("2. 删除学生\n");
        printf("3. 修改学生\n");
        printf("4. 查询学生\n");
        printf("5. 退出\n");
        printf("请选择操作: ");
        cin >> choice;
        
        switch(choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: updateStudent(); break;
            case 4: queryStudents(); break;
            case 5: 
                printf("程序即将退出，按回车键关闭窗口...\n");
                system("pause");
                return 0;
            default: printf("无效选择！\n");
        }
    }
}