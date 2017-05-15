/**
 * 1028. 人口普查(20)
 * 
 * 某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。
 * 
 * 这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过200岁的
 * 老人，而今天是2014年9月6日，所以超过200岁的生日和未出生的生日都是不合理的，应该
 * 被过滤掉。
 * 
 * 输入格式：
 * 
 * 输入在第一行给出正整数N，取值在(0, 10^5]；随后N行，每行给出1个人的姓名（由不超过
 * 5个英文字母组成的字符串）、以及按“yyyy/mm/dd”（即年/月/日）格式给出的生日。题目
 * 保证最年长和最年轻的人没有并列。
 * 
 * 输出格式：
 * 
 * 在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。
 * 
 * 输入样例：
 * 5
 * John 2001/05/12
 * Tom 1814/09/06
 * Ann 2121/01/30
 * James 1814/09/05
 * Steve 1967/11/20
 * 输出样例：
 * 3 Tom John
 */
#include <stdio.h>
#include <string.h>

int main()
{
    int N, count = 0;
    /* store name and birthday in one string: "YYYY/MM/DD\0NAMES\0" */
    char cur[17], eldest[17] = {'9'}, youngest[17] = {'0'};
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%s %s", cur + 11, cur);
        if(strcmp(cur, "1814/09/06") >= 0 && strcmp(cur, "2014/09/06") <= 0) 
        {
            if(strcmp(cur, eldest) <= 0) 
                memcpy(eldest, cur, 17);
            if(strcmp(cur, youngest) >= 0)
                memcpy(youngest, cur, 17);
            count++;
        }
    }
    
    if(count)
        printf("%d %s %s", count, eldest + 11, youngest + 11);
    else 
        printf("0");
    
    return 0;
}
