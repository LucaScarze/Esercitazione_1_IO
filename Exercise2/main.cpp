#include <iostream>
#include <fstream>
#include <iomanip>

double traslazione(double x){
	double t = (3.0/4.0)*x - 7.0/4.0;
	return t;
}

int main()
{
	std::ifstream file("./data.txt");
	if (file.fail())
	{
		std::cerr <<"Non è stato possibile aprire il file"<< std::endl;
		return 1;
	}
	int i = 1;
	double sum = 0;
	double val;
	std::ofstream results("./results.txt");
	results << "# N mean" << std::endl;
	if (results.is_open()){
		while(file >> val)
		{
			double new_val = traslazione(val);
			sum = sum + new_val;
			double mean = sum/i;
			results << i << " " << std::scientific << std::setprecision(16)<<mean <<std::endl;
			i ++;
		}
	}
	results.close();
    return 0;
}
