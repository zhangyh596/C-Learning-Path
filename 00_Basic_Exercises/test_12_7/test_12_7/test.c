#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 定义最大课程数量和字符串长度限制
#define MAX_COURSES 100
#define STR_LEN 50

// 定义课程结构体 (对应要求中的"信息要素")
typedef struct {
    int id;                 // 内部编号，用于唯一标识
    char name[STR_LEN];     // 课程名称
    char teacher[STR_LEN];  // 授课老师
    char location[STR_LEN]; // 地点
    char time[STR_LEN];     // 时间
} Course;

// 全局变量
Course courses[MAX_COURSES]; // 存储课程的数组
int courseCount = 0;         // 当前课程数量

// 函数声明
void initCourses();
void displayMenu();
void printHeader();
void printCourse(Course c);
void listCourses();
void addCourse();
void searchCourse();
void deleteCourse();
int findCourseIndexByName(char* name);

int main() {
    int choice;

    // 1. 初始化课程数据 (对应要求：启动时显示初始列表)
    initCourses();

    printf("========================================\n");
    printf("   欢迎使用课程管理系统 (2025作业版)    \n");
    printf("========================================\n");

    // 启动后立即显示一次列表
    listCourses();

    while (1) {
        displayMenu();
        printf("请输入选项 (0-4): ");
        // 防止输入非数字导致的死循环
        if (scanf("%d", &choice) != 1) {
            printf("输入无效，请输入数字！\n");
            while (getchar() != '\n'); // 清空缓冲区
            continue;
        }

        switch (choice) {
        case 1:
            listCourses(); // 显示课程列表
            break;
        case 2:
            searchCourse(); // 查询课程信息
            break;
        case 3:
            addCourse(); // 添加课程信息
            break;
        case 4:
            deleteCourse(); // 删除课程信息
            break;
        case 0:
            printf("退出系统。再见！\n");
            return 0;
        default:
            printf("无效的选项，请重新输入。\n");
        }
    }
    return 0;
}

/*
 * 函数：初始化课程
 * 功能：预先加载至少3-4门课程信息 (对应作业要求)
 */
void initCourses() {
    // 课程 1
    courses[courseCount].id = 1;
    strcpy(courses[courseCount].name, "C语言程序设计");
    strcpy(courses[courseCount].teacher, "张教授");
    strcpy(courses[courseCount].location, "一教101");
    strcpy(courses[courseCount].time, "周一8:00");
    courseCount++;

    // 课程 2
    courses[courseCount].id = 2;
    strcpy(courses[courseCount].name, "数据结构");
    strcpy(courses[courseCount].teacher, "李老师");
    strcpy(courses[courseCount].location, "二教203");
    strcpy(courses[courseCount].time, "周二10:00");
    courseCount++;

    // 课程 3
    courses[courseCount].id = 3;
    strcpy(courses[courseCount].name, "计算机网络");
    strcpy(courses[courseCount].teacher, "王博士");
    strcpy(courses[courseCount].location, "实验楼405");
    strcpy(courses[courseCount].time, "周三14:00");
    courseCount++;

    // 课程 4
    courses[courseCount].id = 4;
    strcpy(courses[courseCount].name, "高等数学");
    strcpy(courses[courseCount].teacher, "赵老师");
    strcpy(courses[courseCount].location, "三教302");
    strcpy(courses[courseCount].time, "周五8:00");
    courseCount++;
}

/*
 * 函数：显示菜单
 */
void displayMenu() {
    printf("\n---------------- 功能菜单 ----------------\n");
    printf("1. 显示课程列表\n");
    printf("2. 查询课程信息\n");
    printf("3. 添加课程信息\n");
    printf("4. 删除课程信息\n");
    printf("0. 退出系统\n");
    printf("------------------------------------------\n");
}

/*
 * 辅助函数：打印表头
 */
void printHeader() {
    printf("\n%-20s %-15s %-15s %-15s\n", "课程名称", "授课老师", "地点", "时间");
    printf("------------------------------------------------------------------\n");
}

/*
 * 辅助函数：打印单行课程信息
 */
void printCourse(Course c) {
    printf("%-20s %-15s %-15s %-15s\n", c.name, c.teacher, c.location, c.time);
}

/*
 * 功能：显示课程列表
 * 对应要求：显示初始的课程信息列表
 */
void listCourses() {
    if (courseCount == 0) {
        printf("\n当前没有课程信息。\n");
        return;
    }
    printHeader();
    for (int i = 0; i < courseCount; i++) {
        printCourse(courses[i]);
    }
    printf("------------------------------------------------------------------\n");
    printf("共找到 %d 门课程。\n", courseCount);
}

/*
 * 功能：添加课程信息
 * 对应要求：输入新的课程信息扩展课程管理
 */
void addCourse() {
    if (courseCount >= MAX_COURSES) {
        printf("课程列表已满，无法添加！\n");
        return;
    }

    printf("\n--- 添加新课程 ---\n");

    // 生成简单的ID
    courses[courseCount].id = courseCount + 1;

    printf("请输入课程名称: ");
    scanf("%s", courses[courseCount].name);

    printf("请输入授课老师: ");
    scanf("%s", courses[courseCount].teacher);

    printf("请输入地点: ");
    scanf("%s", courses[courseCount].location);

    printf("请输入时间 (如:周一8:00): ");
    scanf("%s", courses[courseCount].time);

    courseCount++;
    printf("添加成功！\n");
}

/*
 * 功能：查询课程信息
 * 对应要求：输入关键字(名称、老师等)查询
 */
void searchCourse() {
    char keyword[STR_LEN];
    int found = 0;

    printf("\n请输入查询关键字 (课程名或老师): ");
    scanf("%s", keyword);

    printf("\n--- 查询结果 ---\n");

    // 遍历数组进行模糊匹配
    // strstr 用于检查 keyword 是否包含在目标字符串中
    for (int i = 0; i < courseCount; i++) {
        if (strstr(courses[i].name, keyword) != NULL ||
            strstr(courses[i].teacher, keyword) != NULL) {

            if (!found) printHeader(); // 第一次找到时打印表头
            printCourse(courses[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("未找到包含 \"%s\" 的课程。\n", keyword);
    }
}

/*
 * 辅助函数：通过完全匹配名称查找数组下标
 */
int findCourseIndexByName(char* name) {
    for (int i = 0; i < courseCount; i++) {
        if (strcmp(courses[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

/*
 * 功能：删除课程信息
 * 对应要求：查询后进行删除
 */
void deleteCourse() {
    char name[STR_LEN];
    char confirm;

    printf("\n--- 删除课程 ---\n");
    printf("请输入要删除的课程完整名称: ");
    scanf("%s", name);

    int index = findCourseIndexByName(name);

    if (index == -1) {
        printf("错误：未找到名称为 \"%s\" 的课程。\n", name);
        return;
    }

    // 显示即将删除的课程信息
    printf("\n找到以下课程，确定要删除吗？\n");
    printHeader();
    printCourse(courses[index]);

    printf("\n确认删除? (y/n): ");
    getchar(); // 吃掉之前的换行符
    scanf("%c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {
        // 删除逻辑：将该位置之后的所有元素前移一位
        for (int i = index; i < courseCount - 1; i++) {
            courses[i] = courses[i + 1];
        }
        courseCount--;
        printf("删除成功！\n");
    }
    else {
        printf("已取消删除操作。\n");
    }
}

//#define _CRT_SECURE_NO_WARNINGS  // 在VS中忽略scanf等安全警告
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <ctype.h> // 用于字符处理
//
//#define MAX_COURSES 100
//#define FILE_NAME "course_data.txt"
//
//// 定义课程结构体
//typedef struct {
//    char name[50];      // 课程名称
//    char teacher[30];   // 授课老师
//    char location[50];  // 地点
//    char time[50];      // 时间
//} Course;
//
//// 全局变量，方便各函数调用
//Course courses[MAX_COURSES];
//int currentCount = 0;
//
//// --- 辅助工具函数 ---
//
//// 去掉字符串末尾的换行符 (处理fgets留下的\n)
//void trim(char* str) {
//    size_t len = strlen(str);
//    if (len > 0 && str[len - 1] == '\n') {
//        str[len - 1] = '\0';
//    }
//}
//
//// 将字符串转为小写，用于不区分大小写的比较
//void toLowerStr(char* src, char* dest) {
//    int i = 0;
//    while (src[i]) {
//        dest[i] = tolower(src[i]);
//        i++;
//    }
//    dest[i] = '\0';
//}
//
//// --- 核心功能函数 ---
//
//// [创新点]：从文件加载数据，如果文件不存在则加载默认作业要求的3-4门课
//void loadData() {
//    FILE* fp = fopen(FILE_NAME, "r");
//    if (fp == NULL) {
//        // 文件不存在，初始化默认数据 (满足作业要求1)
//        Course defaults[] = {
//            {"C语言程序设计", "王教授", "信息楼201", "周一 08:00"},
//            {"数据结构", "李老师", "理工楼305", "周三 10:00"},
//            {"高等数学", "张老师", "主楼101", "周二 14:00"},
//            {"大学英语", "Smith", "外语楼404", "周五 09:50"}
//        };
//        int defaultSize = sizeof(defaults) / sizeof(defaults[0]);
//        for (int i = 0; i < defaultSize; i++) {
//            courses[i] = defaults[i];
//        }
//        currentCount = defaultSize;
//        printf("[系统提示] 首次运行，已加载默认课程数据。\n");
//    }
//    else {
//        // 从文件读取
//        currentCount = 0;
//        while (fscanf(fp, "%s %s %s %s",
//            courses[currentCount].name,
//            courses[currentCount].teacher,
//            courses[currentCount].location,
//            courses[currentCount].time) != EOF) {
//            currentCount++;
//        }
//        fclose(fp);
//        printf("[系统提示] 成功加载 %d 条课程记录。\n", currentCount);
//    }
//}
//
//// [创新点]：保存数据到文件
//void saveData() {
//    FILE* fp = fopen(FILE_NAME, "w");
//    if (fp == NULL) {
//        printf("[错误] 无法保存数据！\n");
//        return;
//    }
//    for (int i = 0; i < currentCount; i++) {
//        fprintf(fp, "%s %s %s %s\n",
//            courses[i].name,
//            courses[i].teacher,
//            courses[i].location,
//            courses[i].time);
//    }
//    fclose(fp);
//    printf("[系统提示] 数据已自动保存。\n");
//}
//
//// 显示单条课程信息（格式化输出）
//void printHeader() {
//    printf("%-5s %-20s %-15s %-15s %-15s\n", "ID", "课程名称", "教师", "地点", "时间");
//    printf("----------------------------------------------------------------------\n");
//}
//
//void printRow(int index) {
//    printf("%-5d %-20s %-15s %-15s %-15s\n",
//        index + 1,
//        courses[index].name,
//        courses[index].teacher,
//        courses[index].location,
//        courses[index].time);
//}
//
//// 1. 显示所有课程
//void showAll() {
//    if (currentCount == 0) {
//        printf("\n当前没有课程信息。\n");
//        return;
//    }
//    printf("\n=== 所有课程列表 ===\n");
//    printHeader();
//    for (int i = 0; i < currentCount; i++) {
//        printRow(i);
//    }
//}
//
//// 3. 添加课程
//void addCourse() {
//    if (currentCount >= MAX_COURSES) {
//        printf("课程已满，无法添加！\n");
//        return;
//    }
//
//    Course c;
//    // 使用fgets代替scanf，防止空格截断输入
//    getchar(); // 清除缓冲区
//
//    printf("\n=== 添加新课程 ===\n");
//    printf("请输入课程名称: ");
//    fgets(c.name, 50, stdin); trim(c.name);
//
//    printf("请输入授课老师: ");
//    fgets(c.teacher, 30, stdin); trim(c.teacher);
//
//    printf("请输入地点: ");
//    fgets(c.location, 50, stdin); trim(c.location);
//
//    printf("请输入时间(如:周一8点): ");
//    fgets(c.time, 50, stdin); trim(c.time);
//
//    courses[currentCount] = c;
//    currentCount++;
//    printf(">> 添加成功！\n");
//    saveData(); // 实时保存
//}
//
//// 删除指定索引的课程
//void deleteAtIndex(int index) {
//    printf("正在删除: %s ... ", courses[index].name);
//    // 简单的数组前移操作
//    for (int i = index; i < currentCount - 1; i++) {
//        courses[i] = courses[i + 1];
//    }
//    currentCount--;
//    printf("删除完成。\n");
//    saveData();
//}
//
//// 2. & 4. 查询与删除 (二合一功能，满足作业要求的“查询后删除”)
//void searchAndOp() {
//    char keyword[50];
//    char tempName[50], tempTeacher[30], tempKey[50];
//    int foundIndex[MAX_COURSES]; // 记录找到的课程原始下标
//    int foundCount = 0;
//
//    printf("\n请输入查询关键字 (课程名或老师): ");
//    scanf("%s", keyword);
//    toLowerStr(keyword, tempKey); // 关键字转小写
//
//    printf("\n=== 查询结果 ===\n");
//    printHeader();
//
//    for (int i = 0; i < currentCount; i++) {
//        // 制作临时的小写副本进行比对，实现模糊搜索
//        toLowerStr(courses[i].name, tempName);
//        toLowerStr(courses[i].teacher, tempTeacher);
//
//        if (strstr(tempName, tempKey) || strstr(tempTeacher, tempKey)) {
//            printf("%-5d ", foundCount + 1); // 显示临时的序号 1, 2, 3...
//            printf("%-20s %-15s %-15s %-15s\n",
//                courses[i].name, courses[i].teacher, courses[i].location, courses[i].time);
//
//            foundIndex[foundCount] = i; // 记住它在全局数组中的真实位置
//            foundCount++;
//        }
//    }
//
//    if (foundCount == 0) {
//        printf("未找到相关课程。\n");
//        return;
//    }
//
//    // 满足作业要求：查询后可以进行删除
//    printf("----------------------------------------------------------------------\n");
//    printf("输入 0 返回菜单，或输入上表中的【ID】来删除对应课程: ");
//
//    int choice;
//    scanf("%d", &choice);
//
//    if (choice > 0 && choice <= foundCount) {
//        int realIndex = foundIndex[choice - 1];
//
//        // 二次确认，增加交互友好度
//        printf("确定要删除 \"%s\" 吗? (1=是, 0=否): ", courses[realIndex].name);
//        int confirm;
//        scanf("%d", &confirm);
//        if (confirm == 1) {
//            deleteAtIndex(realIndex);
//        }
//    }
//}
//
//// 主菜单
//void menu() {
//    printf("\n================================\n");
//    printf("   课程管理系统 v1.0 (Dev by Student)\n");
//    printf("================================\n");
//    printf("   1. 显示所有课程\n");
//    printf("   2. 查询课程 (支持删除)\n");
//    printf("   3. 添加新课程\n");
//    printf("   0. 退出系统\n");
//    printf("================================\n");
//    printf("请选择操作: ");
//}
//
//int main() {
//    // 设置控制台编码，防止乱码（可选）
//    system("chcp 65001");
//
//    loadData(); // 程序启动时加载
//
//    int choice;
//    while (1) {
//        menu();
//        if (scanf("%d", &choice) != 1) {
//            // 处理非数字输入导致的死循环
//            while (getchar() != '\n');
//            continue;
//        }
//
//        switch (choice) {
//        case 1: showAll(); break;
//        case 2: searchAndOp(); break;
//        case 3: addCourse(); break;
//        case 0:
//            printf("感谢使用，再见！\n");
//            return 0;
//        default: printf("无效输入，请重试。\n");
//        }
//    }
//    return 0;
//}