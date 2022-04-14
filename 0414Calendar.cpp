#include<stdio.h>

int main() {
    const int WIDTH = 7;

    while (true) {
        int year, month;
        int dayOfWeek; // 요일 : 월 화 수 목 금 토 일 ( 0 1 2 3 4 5 6 ) 
        int days = 0; // 1900년부터 지난 일 수 저장하는 변수 , 초기화 
        int yearsum = 0; // 1900년부터 지난 일 수  더하기 ( 현재 년도 이전 까지 년만 )  , 초기화
        int monthsum = 0; // 1900년부터 지난 일 수  더하기 ( 현재 년도 1월부터 지난 월 까지만 )  , 초기화
        int monthdaycount = 0;
        printf("년도 입력 : ");
        scanf("%d", & year);
        if (year == 0) {
            printf("종료합니다."); // 0년을 입력하면 반복 종료  
            break;
        }
        printf("월 입력 : ");
        scanf("%d", & month);

        // 윤년 일때 366일 + 
        for (int indexA = 1900; indexA < year; indexA++) {
            if ((indexA % 4 == 0) && !(indexA % 100 == 0) || (indexA % 400 == 0)) {
                yearsum += 366;
            } else {
                yearsum += 365;
            }
        }
        // 윤년 일때 3 ~ 12월 은 +1 
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

        days = yearsum + monthsum; // 1900년부터 지난 일 수 
        dayOfWeek = days % 7; // 요일 : 월 화 수 목 금 토 일 ( 0 1 2 3 4 5 6 ) 

        // 달력에 숫자 찍기 
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

        printf("======================%d년 %d월====================\n", year, month);
        printf("일\t월\t화\t수\t목\t금\t토\n");

        // 월요일에 시작하는 달 
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
            // 화요일에 시작하는 달
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
            // 수요일에 시작하는 달
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
            // 목요일에 시작하는 달
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
            // 금요일에 시작하는 달
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
            // 토요일에 시작하는 달
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
            // 일요일에 시작하는 달
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
