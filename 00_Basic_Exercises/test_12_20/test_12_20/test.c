#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define COLOR_RESET  "\033[0m"
#define COLOR_RED    "\033[31m"
#define COLOR_GREEN  "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE   "\033[34m"
#define COLOR_BOLD   "\033[1m"

//定义结构体：课程包含的信息
typedef struct
{
    int id;            //课程序号
    char name[50];     //课程名称
    char teacher[50];  //课程老师
    char location[50]; //课程地点
    char time[50];     //课程时间
} Course;

//全局变量：存储课程信息
Course courses[100];
//全局变量：记录课程数量
int coursecount = 0;

//函数声明
void show_all_courses();         //显示列表
void menu();                     //显示菜单
void search_course();            //搜索
void add_course();               //添加
void save_courses_to_file();     //保存数据
void delete_course();            //删除
void sort_all_courses_by_name(); //排序
void print_header();             //打印表头

int main()
{
    system("color");

    //1.尝试打开文件
    FILE* fp = fopen("course_data.txt", "r");

    if (NULL == fp)
    {
        // 如果文件不存在，初始化默认数据
        printf(COLOR_YELLOW "提示：未找到存档文件，正在初始化默认数据...\n" COLOR_RESET);

        // 使用复合字面量初始化
        courses[coursecount++] = (Course){ 1,"C语言程序设计","陈老师","106栋","周二 10:00" };
        courses[coursecount++] = (Course){ 2,"地理科学导论","薛老师","逸夫楼","周五 10:00" };
        courses[coursecount++] = (Course){ 3,"高等数学","万老师","逸夫楼","周一 15:00" };
        courses[coursecount++] = (Course){ 4,"国土空间规划","马老师","丰盛堂","周一 17:00" };
    }
    else
    {
        // 如果文件存在，循环读取
        while (fscanf(fp, "%d %s %s %s %s",
            &courses[coursecount].id,
            courses[coursecount].name,
            courses[coursecount].teacher,
            courses[coursecount].location,
            courses[coursecount].time) == 5)
        {
            coursecount++;
        }
        fclose(fp); //读取完成关闭文件
    }

    printf(COLOR_GREEN "成功加载%d条课程记录！\n" COLOR_RESET, coursecount);

    //进入主菜单循环
    int choice;
    printf(COLOR_BOLD COLOR_BLUE "***欢迎使用课程管理系统***\n" COLOR_RESET);
    show_all_courses(); //展示所有课程

    while (1)
    {
        menu(); //打印菜单
        printf("请输入选择（1-6）：");

        // 验证用户的选择，防止输入字母死循环
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n'); // 清空缓冲区
            choice = 0;
        }

        switch (choice)
        {
        case 1:
            show_all_courses(); //显示
            break;
        case 2:
            search_course(); //查询
            break;
        case 3:
            add_course(); //添加
            save_courses_to_file(); //保存
            break;
        case 4:
            delete_course(); //删除
            save_courses_to_file(); //保存
            break;
        case 5:
            sort_all_courses_by_name(); //排序
            save_courses_to_file(); //保存
            break;
        case 6:
            printf(COLOR_GREEN "正在保存数据并退出...感谢使用！\n" COLOR_RESET);
            save_courses_to_file(); //退出前最后一次保存
            return 0;
        default:
            printf(COLOR_RED "输入错误，请重新输入\n" COLOR_RESET);
            break;
        }
    }
    return 0;
}

//功能函数的实现
void show_all_courses()
{
    if (coursecount == 0)
    {
        printf(COLOR_YELLOW "当前列表为空\n" COLOR_RESET);
        return;
    }
    print_header();
    for (int i = 0; i < coursecount; i++)
    {
        printf("%-5d %-15s %-10s %-10s %-15s\n",
            courses[i].id, courses[i].name, courses[i].teacher, courses[i].location, courses[i].time);
    }
}

void menu()
{
    printf("\n************************\n");
    printf("1.显示所有课程\n");
    printf("2.查询课程信息\n");
    printf("3.添加课程信息\n");
    printf("4.删除课程信息\n");
    printf(COLOR_BLUE "5.课程排序（按名称）\n" COLOR_RESET);
    printf("6.退出系统\n");
    printf("************************\n");
}

void search_course()
{
    char keyword[50];
    printf("请输入查询关键字: ");
    scanf("%s", keyword);

    printf("\n正在查询...\n");
    int found = 0;

    for (int i = 0; i < coursecount; i++)
    {
        if (strstr(courses[i].name, keyword) != NULL || strstr(courses[i].teacher, keyword) != NULL)
        {
            if (!found)
            {
                print_header();
            }
            printf("%-5d %-15s %-10s %-10s %-15s\n",
                courses[i].id, courses[i].name, courses[i].teacher, courses[i].location, courses[i].time);
            found = 1;
        }
    }
    if (!found)
    {
        printf(COLOR_YELLOW "未找到相关课程。\n" COLOR_RESET);
    }
}

void add_course()
{
    if (coursecount >= 100)
    {
        printf(COLOR_RED "课程库已满！\n" COLOR_RESET);
        return;
    }

    Course newCourse;
    // 自动计算新ID
    int maxId = 0;
    for (int i = 0; i < coursecount; i++)
    {
        if (courses[i].id > maxId)
        {
            maxId = courses[i].id;
        }
    }
    newCourse.id = maxId + 1;

    printf("请输入课程名称: ");
    scanf("%s", newCourse.name);
    printf("请输入授课老师: ");
    scanf("%s", newCourse.teacher);
    printf("请输入地点: ");
    scanf("%s", newCourse.location);
    printf("请输入时间: ");
    scanf("%s", newCourse.time);

    courses[coursecount++] = newCourse;
    printf(COLOR_GREEN "添加成功 (ID: %d)！\n" COLOR_RESET, newCourse.id);
}

void save_courses_to_file()
{
    FILE* fp = fopen("course_data.txt", "w");
    if (fp == NULL)
    {
        printf(COLOR_RED "错误：无法写入文件！\n" COLOR_RESET);
        return;
    }
    for (int i = 0; i < coursecount; i++)
    {
        fprintf(fp, "%d %s %s %s %s\n",
            courses[i].id, courses[i].name, courses[i].teacher, courses[i].location, courses[i].time);
    }
    fclose(fp);
}

void delete_course()
{
    char keyword[50];
    printf("请输入关键字查找要删除的课程: ");
    scanf("%s", keyword);

    // 1. 展示匹配项
    int found = 0;
    for (int i = 0; i < coursecount; i++)
    {
        if (strstr(courses[i].name, keyword) != NULL || strstr(courses[i].teacher, keyword) != NULL)
        {
            if (!found)
            {
                print_header();
            }
            printf("%-5d %-15s %-10s %-10s %-15s\n",
                courses[i].id, courses[i].name, courses[i].teacher, courses[i].location, courses[i].time);
            found = 1;
        }
    }

    if (!found)
    {
        printf(COLOR_YELLOW "未找到课程，取消操作。\n" COLOR_RESET);
        return;
    }

    // 2. 通过ID确认删除
    int targetId;
    printf("\n请输入要删除的ID (输入 -1 取消): ");
    scanf("%d", &targetId);

    if (targetId == -1)
    {
        return;
    }

    int idx = -1;
    for (int i = 0; i < coursecount; i++)
    {
        if (courses[i].id == targetId)
        {
            idx = i;
            break;
        }
    }

    if (idx != -1)
    {
        // 数组移位覆盖
        for (int j = idx; j < coursecount - 1; j++)
        {
            courses[j] = courses[j + 1];
        }
        coursecount--;
        printf(COLOR_GREEN "删除成功。\n" COLOR_RESET);
    }
    else
    {
        printf(COLOR_RED "无效ID。\n" COLOR_RESET);
    }
}

void sort_all_courses_by_name()
{
    if (coursecount < 2)
    {
        printf("无需排序\n");
        return;
    }
    //冒泡排序
    for (int i = 0; i < coursecount - 1; i++)
    {
        for (int j = 0; j < coursecount - 1 - i; j++)
        {
            if (strcmp(courses[j].name, courses[j + 1].name) > 0)
            {
                Course tmp = courses[j];
                courses[j] = courses[j + 1];
                courses[j + 1] = tmp;
            }
        }
    }
    printf(COLOR_GREEN "排序完成\n" COLOR_RESET);
    show_all_courses();
}

void print_header()
{
    printf(COLOR_BOLD "\n%-5s %-15s %-10s %-10s %-15s\n", "ID", "课程名称", "授课老师", "地点", "时间" COLOR_RESET);
    printf("************************************************************************\n");
}
