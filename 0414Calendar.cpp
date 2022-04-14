#include<stdio.h>

int main() {
    const int WIDTH = 7;

    while (true) {
        int year, month;
        int dayOfWeek; // ���� : �� ȭ �� �� �� �� �� ( 0 1 2 3 4 5 6 ) 
        int days = 0; // 1900����� ���� �� �� �����ϴ� ���� , �ʱ�ȭ 
        int yearsum = 0; // 1900����� ���� �� ��  ���ϱ� ( ���� �⵵ ���� ���� �⸸ )  , �ʱ�ȭ
        int monthsum = 0; // 1900����� ���� �� ��  ���ϱ� ( ���� �⵵ 1������ ���� �� ������ )  , �ʱ�ȭ
        int monthdaycount = 0;
        printf("�⵵ �Է� : ");
        scanf("%d", & year);
        if (year == 0) {
            printf("�����մϴ�."); // 0���� �Է��ϸ� �ݺ� ����  
            break;
        }
        printf("�� �Է� : ");
        scanf("%d", & month);

        // ���� �϶� 366�� + 
        for (int indexA = 1900; indexA < year; indexA++) {
            if ((indexA % 4 == 0) && !(indexA % 100 == 0) || (indexA % 400 == 0)) {
                yearsum += 366;
            } else {
                yearsum += 365;
            }
        }
        // ���� �϶� 3 ~ 12�� �� +1 
        if ((year % 4 == 0) && !(year % 100 == 0) || (year % 400 == 0)) {
            if (month == 1) {
                monthsum = 0;
            } else if (month == 2) {
                monthsum = 31;
            } else if (month == 3) {
                monthsum = 31 + 29;
            } else if (month == 4) {
                monthsum = 31 + 29 + 31;
            } else if (month == 5) {
                monthsum = 31 + 29 + 31 + 30;
            } else if (month == 6) {
                monthsum = 31 + 29 + 31 + 30 + 31;
            } else if (month == 7) {
                monthsum = 31 + 29 + 31 + 30 + 31 + 30;
            } else if (month == 8) {
                monthsum = 31 + 29 + 31 + 30 + 31 + 30 + 31;
            } else if (month == 9) {
                monthsum = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31;
            } else if (month == 10) {
                monthsum = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
            } else if (month == 11) {
                monthsum = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
            } else if (month == 12) {
                monthsum = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
            }
        } else {
            if (month == 1) {
                monthsum = 0;
            } else if (month == 2) {
                monthsum = 31;
            } else if (month == 3) {
                monthsum = 31 + 28;
            } else if (month == 4) {
                monthsum = 31 + 28 + 31;
            } else if (month == 5) {
                monthsum = 31 + 28 + 31 + 30;
            } else if (month == 6) {
                monthsum = 31 + 28 + 31 + 30 + 31;
            } else if (month == 7) {
                monthsum = 31 + 28 + 31 + 30 + 31 + 30;
            } else if (month == 8) {
                monthsum = 31 + 28 + 31 + 30 + 31 + 30 + 31;
            } else if (month == 9) {
                monthsum = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
            } else if (month == 10) {
                monthsum = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
            } else if (month == 11) {
                monthsum = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
            } else if (month == 12) {
                monthsum = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
            }
        }

        days = yearsum + monthsum; // 1900����� ���� �� �� 
        dayOfWeek = days % 7; // ���� : �� ȭ �� �� �� �� �� ( 0 1 2 3 4 5 6 ) 

        // �޷¿� ���� ��� 
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            monthdaycount = 31;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            monthdaycount = 30;
        } else if (month == 2) {
            if ((year % 4 == 0) && !(year % 100 == 0) || (year % 400 == 0)) {
                monthdaycount = 29;
            } else {
                monthdaycount = 28;
            }
        }

        printf("======================%d�� %d��====================\n", year, month);
        printf("��\t��\tȭ\t��\t��\t��\t��\n");

        // �����Ͽ� �����ϴ� �� 
        if (dayOfWeek == 0) {
            printf("\t%d\t%d\t%d\t%d\t%d\t%d\n", 1, 2, 3, 4, 5, 6);
            for (int indexA = 7; indexA <= monthdaycount; indexA += WIDTH) {
                for (int indexB = 0; indexB < 7; indexB++) {
                    if ((indexA + indexB) > monthdaycount) {
                        break;
                    }
                    printf("%d\t", (indexA + indexB));
                }
                printf("\n");
            }
            // ȭ���Ͽ� �����ϴ� ��
        } else if (dayOfWeek == 1) {
            printf("\t\t%d\t%d\t%d\t%d\t%d\n", 1, 2, 3, 4, 5);
            for (int indexA = 6; indexA <= monthdaycount; indexA += WIDTH) {
                for (int indexB = 0; indexB < 7; indexB++) {
                    if ((indexA + indexB) > monthdaycount) {
                        break;
                    }
                    printf("%d\t", (indexA + indexB));
                }
                printf("\n");
            }
            // �����Ͽ� �����ϴ� ��
        } else if (dayOfWeek == 2) {
            printf("\t\t\t%d\t%d\t%d\t%d\n", 1, 2, 3, 4);
            for (int indexA = 5; indexA <= monthdaycount; indexA += WIDTH) {
                for (int indexB = 0; indexB < 7; indexB++) {
                    if ((indexA + indexB) > monthdaycount) {
                        break;
                    }
                    printf("%d\t", (indexA + indexB));
                }
                printf("\n");
            }
            // ����Ͽ� �����ϴ� ��
        } else if (dayOfWeek == 3) {
            printf("\t\t\t\t%d\t%d\t%d\n", 1, 2, 3);
            for (int indexA = 4; indexA <= monthdaycount; indexA += WIDTH) {
                for (int indexB = 0; indexB < 7; indexB++) {
                    if ((indexA + indexB) > monthdaycount) {
                        break;
                    }
                    printf("%d\t", (indexA + indexB));
                }
                printf("\n");
            }
            // �ݿ��Ͽ� �����ϴ� ��
        } else if (dayOfWeek == 4) {
            printf("\t\t\t\t\t%d\t%d\n", 1, 2);
            for (int indexA = 3; indexA <= monthdaycount; indexA += WIDTH) {
                for (int indexB = 0; indexB < 7; indexB++) {
                    if ((indexA + indexB) > monthdaycount) {
                        break;
                    }
                    printf("%d\t", (indexA + indexB));
                }
                printf("\n");
            }
            // ����Ͽ� �����ϴ� ��
        } else if (dayOfWeek == 5) {
            printf("\t\t\t\t\t\t%d\n", 1);
            for (int indexA = 2; indexA <= monthdaycount; indexA += WIDTH) {
                for (int indexB = 0; indexB < 7; indexB++) {
                    if ((indexA + indexB) > monthdaycount) {
                        break;
                    }
                    printf("%d\t", (indexA + indexB));
                }
                printf("\n");
            }
            // �Ͽ��Ͽ� �����ϴ� ��
        } else if (dayOfWeek == 6) {
            for (int indexA = 1; indexA <= monthdaycount; indexA += WIDTH) {
                for (int indexB = 0; indexB < 7; indexB++) {
                    if ((indexA + indexB) > monthdaycount) {
                        break;
                    }
                    printf("%d\t", (indexA + indexB));
                }
                printf("\n");
            }
        }
    }
    return 0;
}
