using namespace std;

//A class to represent matrices
class Matrx
{
private:
	int nRow;
	int nCol;
	double **ary;
	double **dummy;
public:
	Matrx(int nRow, int nCol);

	void printMatrx();
	void adjustRowElements(int row_num, double *s);
	void assignValue(double *s);  
	void transpose();	
};

Matrx::Matrx(int nRow, int nCol) //constructor
{
	this -> nRow = nRow;
	this -> nCol = nCol;

	//create a dynamic array of pointers
	ary = new double *[nRow];

	//create a row for every pointer
	for (int i=0; i<nRow; i++)
	{
		ary[i] = new double[nCol];
		//initialize all entries as false to indicate that 
		//there are edges initially
		memset(ary[i], false, nCol*sizeof(double));
	}
}

void Matrx::printMatrx() //print out matrix
{
	for (int u=0; u<nRow; u++){
		for (int v=0; v<nCol; v++){
			cout << ary[u][v] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Matrx::adjustRowElements(int nth_row, double *s)
/* Adjust the entire row in the matix
   nth_row: n-th row that to be adjusted
   *s: 1D arry, the entire row elements
*/
{
	// for (int u=0; u<nRow; u++){
	// 	adj[u]=s;
	// }
	ary[nth_row-1] =s;
}

void Matrx::assignValue(double *s)
//ass the vlaues in a 2D array to a matrix object
{	
	for (int i=0; i<(nRow); i++){
		ary[i] = &s[i*3];
	}
}

void Matrx::transpose()
{
	dummy = new double *[nCol];
	for (int i=0; i<nCol; i++){
		dummy[i] = new double[nRow];
		memset(dummy[i], false, nRow*sizeof(double));
	}

	for (int i=0; i<nCol; ++i){	
		for(int j=0; j<nRow; ++j) { dummy[i][j] = ary[j][i]; }
	}	
	ary = dummy;
	
	// swap nRow and nCol after transpose is done
	int nDummy = nRow;
	nRow = nCol; 
	nCol = nDummy;
}


