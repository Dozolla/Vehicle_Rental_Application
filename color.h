#ifndef COLOR_H
#define COLOR_H

void bg_color(int color)
{
    switch (color)
    {
    case 1: // Red:
        printf("\033[0;41m");
        break;
    case 2: // Green:
        printf("\033[0;42m");
        break;
    case 3: // Yellow:
        printf("\033[0;43m");
        break;
    case 4: // Blue:
        printf("\033[0;44m");
        break;
    case 5: // Purple:
        printf("\033[0;45m");
        break;
    case 6: // Cyan:
        printf("\033[0;46m");
        break;
    case 7: // White:
        printf("\033[0;47m");
        break;
    case 0: // Reset":
        printf("\033[0;0m");
        break;
    default:
        printf("\033[0;0m");
        break;
    }
}

void fg_color(int color)
{
    switch (color)
    {
    case 1: // Red":
        printf("\033[0;31m");
        break;
    case 2: // Green":
        printf("\033[0;32m");
        break;
    case 3: // Yellow":
        printf("\033[0;33m");
        break;
    case 4: // Blue":
        printf("\033[0;34m");
        break;
    case 5: // Purple:
        printf("\033[0;35m");
        break;
    case 6: // Cyan":
        printf("\033[0;36m");
        break;
    case 7: // White":
        printf("\033[0;37m");
        break;
    // 10-16 are bold text
    case 10: // Red":
        printf("\033[1;31m");
        break;
    case 11: // Green":
        printf("\033[1;32m");
        break;
    case 12: // Yellow":
        printf("\033[1;33m");
        break;
    case 13: // Blue":
        printf("\033[1;34m");
        break;
    case 14: // Purple:
        printf("\033[1;35m");
        break;
    case 15: // Cyan":
        printf("\033[1;36m");
        break;
    case 16: // White":
        printf("\033[1;37m");
        break;
    case 0: // Reset":
        printf("\033[0;0m");
        break;
    default:
        printf("\033[1;0m");
        break;
    }
}

#endif