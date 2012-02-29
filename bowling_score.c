#include <stdio.h>
#include <string.h>

typedef struct {
  int first;
  int second;
  int third;
  int sum;
} score;

score scores[10];

void dump(void) {
  int i;
  for (i = 0; i < 9; i++) {
    printf("%d,%d,%d  ", scores[i].first, scores[i].second, scores[i].sum);
  }
  printf("%d,%d,%d,%d  \n", scores[10].first, scores[10].second, scores[10].third, scores[10].sum);
}

int main(void) {
  int i;
  int point1, point2, point3;

  memset(scores, 0, sizeof(scores));
  for (i = 0; i < 10; i++) {
    scores[i].sum = (i > 0 ? scores[i-1].sum : 0);

    /* 1 */
    scanf("%d", &point1);
    if (point1 == 10) {
	/* strike */
      scores[i].first = -1;
      scores[i].sum += point1;

      if (i > 1 && scores[i-1].first == -1 && scores[i-2].first == -1) {
	printf("point:%d\n", 10+point1);
	scores[i-2].sum += 10 + point1;
	scores[i-1].sum += 10 + point1;
	scores[i].sum += 10 + point1;
      } else if (i > 0 && scores[i-1].second == -2) {
	scores[i-1].sum += point1;
	scores[i].sum += point1;
      }
      dump();
      continue;
    } else {
      scores[i].first = point1;
      scores[i].sum += point1;
    }

    if (scores[i-1].second == -2) {
      scores[i-1].sum += point1;
      scores[i].sum += point1;
    }
    if (i > 1 && scores[i-1].first == -1 && scores[i-2].first == -1) {
      scores[i-2].sum += 10 + point1;
      scores[i-1].sum += 10 + point1;
      scores[i].sum += 10 + point1;
    }

    /* 2 */
    scanf("%d", &point2);
    if (point1 + point2 == 10) {
      /* spare */
      scores[i].second = -2;
      scores[i].sum += point2;
      if (i > 0 && scores[i-1].first == -1) {
	  scores[i-1].sum += point1 + point2;
	  scores[i].sum += point1 + point2;
      }
      dump();
      continue;
    } else {
      scores[i].second = point2;
      scores[i].sum += point2;
    }

    if (i > 0 && scores[i-1].first == -1) {
      scores[i-1].sum += point1 + point2;
      scores[i].sum += point1 + point2;
    }
    /* 10 */
    if (i = 10) {
      if (point1 == 10 || point1 + point2 == 10) {
	scanf("%d", &point3);
	scores[10].third = point3;
	scores[10].sum += point3;
      }
    }
    dump();
  }
  
  return 0;
}
