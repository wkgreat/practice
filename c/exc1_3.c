#include<stdio.h>
/*华氏温度与摄氏温度对照表
  公式：
  c = (5/9)(f-32)
  当fahr=0,20,40,...,300时(步长20)
  打印摄氏温度

  celsius
  fahr
 */
main()
{

	float fahr, celsius;
	int lower, upper, step;

	printf("华氏温度与摄氏温度对照表\n");
	printf("华氏 摄氏\n");

	lower = 0;
	upper = 300;
	step = 20;

	for(fahr=lower;fahr<=upper;fahr+=20)
	{
		celsius=(5*1.0/9)*(fahr-32);
		printf("%3.0f\t%3.0f\n",fahr,celsius);
	}


}
