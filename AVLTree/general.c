#include"general.h"
void date_cpy(date* d1,date* d2)
{
    d1->dd = d2->dd;
    d1->mm = d2->mm;
    d1->yy = d2->yy;
}
Boolean is_equal_date(date d1,date d2)
{
    Boolean ret_val;
    ret_val = FALSE;
    if(d1.dd==d2.dd && d1.mm==d2.mm && d1.yy==d2.yy)
    {
        ret_val = TRUE;
    }
    return ret_val;
}
Boolean valid_date(date d)
{
	Boolean ret_val;
	ret_val = FALSE;
	if (d.mm<=12 && d.mm>0)
	{
		if(d.dd<=31 && d.dd>0)
		{
			switch(d.mm)
			{
				case 4:
				case 6:
				case 9:
				case 11:
					if(d.dd<=30)
					{
						ret_val = TRUE;
					}
				break;
				case 2:
					if(d.yy%4 == 0)
					{
						if(d.dd<=29)
						{
							ret_val = TRUE;
						}
					}
					else
					{
						if(d.dd<=28)
						{
							ret_val = TRUE;
						}
					}
				break;
				default:
					ret_val = TRUE;
			}
		}
	}
	return ret_val;
}
date scan_date()
{
	date d;
	do
	{
		printf("Please enter date in dd mm yyyy format: ");
		scanf("%d %d %d",&d.dd,&d.mm,&d.yy);
	}while(!valid_date(d));
	return d;
}
void print_tclass(travel_class t)
{
	printf("Travelling Class : ");
	switch(t)
	{
		case 0: printf("Sleeper\n");
		break;
		case 1:printf("3AC\n");
		break;
		case 2: printf("2AC\n");
		break;
		case 3:printf("1AC\n");
		break;
	}
}
int compare_date(date d1,date d2)
{
	if(d1.yy>d2.yy)
	{
		return 1;
	}
	else if(d1.yy==d2.yy)
	{
		if(d1.mm>d2.mm)
		{
			return 1;
		}
		else if(d1.mm==d2.mm)
		{
			if(d1.dd>d2.dd)
				return 1;
			else if(d1.dd==d2.dd)
				return 0;
			else
				return -1;
		}
		else
			return -1;
	}
	else
		return -1;
}