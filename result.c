
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int rollNo;
  int math, phy, che, hin, eng;
  int totalMarks;
  float per;

  char *data = getenv("QUERY_STRING");

  printf("Content-Type: text/html\r\n\r\n");

  printf("<html><head><title>Student Result</title></head><body>");

  if (data == NULL ||
      sscanf(data,
             "rollNo=%d&math=%d&phy=%d&che=%d&hin=%d&eng=%d",
             &rollNo, &math, &phy, &che, &hin, &eng) != 6)
  {
    printf("<h2>Invalid form data!</h2>");
    printf("</body></html>");
    return 0;
  }

  if (rollNo < 0 ||
      math < 0 || math > 100 ||
      phy < 0 || phy > 100 ||
      che < 0 || che > 100 ||
      hin < 0 || hin > 100 ||
      eng < 0 || eng > 100)
  {
    printf("<h2>Please enter valid marks between 0 and 100.</h2>");
    printf("</body></html>");
    return 0;
  }

  totalMarks = math + phy + che + hin + eng;

  per = totalMarks / 5.0f;

  printf("<h1>Student Result</h1>");
  printf("<p>Roll Number: %d</p>", rollNo);
  printf("<p>Total Marks: %d / 500</p>", totalMarks);
  printf("<p>Percentage: %.2f%%</p>", per);

  if (per >= 80)
  {
    printf("<p>Grade: A</p>");
  }
  else if (per < 80 && per >= 60)
  {
    printf("<p>Grade: B</p>");
  }
  else if (per < 60 && per >= 40)
  {
    printf("<p>Grade: C</p>");
  }
  else
  {
    printf("<p>Grade: F</p>");
  }

  printf("</body></html>");

  return 0;
}
