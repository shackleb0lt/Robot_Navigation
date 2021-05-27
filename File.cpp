#include "File.h"

/**
 * Function that parses a line and returns all the space separated numbers as vectors
 * @param line character array line to be parsed
 * @param len length of the line to be parsed
 * @return integer vector storing all the numbers in the line.
*/
vector <int> parse_line(char *line,int len)
{
    
    vector<int> args;
    int i=0;
    int sum=0;
    bool start = false;

    while(i<len)    //loop till the line is not finished
    {
        if(line[i]>='0' && line[i]<='9')    // check if the character is a digit 
        {
            if(!start) start = true;        // if yes change the current number 
            sum *= 10;
            sum += line[i]-'0';
        }

        if(!(line[i]>='0' && line[i]<='9') && start) //if character is not a number then ignore 
        {
            args.push_back(sum);
            start = false;
            sum = 0;
        }
        if(line[i]=='\n')break;
        i++;
    }
    
    return args;
}

/**
 * Function that parses a file line by line and initializes a grid object
 * @param filename stores the filename to be openend
 * @return Grid object containing all the data regarding the grid
*/
Grid * parse_file(char * filename)
{
    FILE * fptr = fopen(filename,"r");          //opening the file in read mode 
    if(fptr==NULL)
    {
        printf("File %s not found. Exiting... \n",filename);
        return NULL;                            // returns a NULL pointer if file is not initialized properly 
    }

    int N,M;
    char line[32];
    char lineG[256];

        //checking and parsing the line for N and M values
    if(fgets(line,32,fptr)==NULL)               
    {
        printf("N and M values are missing. Exiting ...\n");
        return NULL;   
    }
    vector<int> argV = parse_line(line,32);
    N = argV[0];
    M = argV[1];
    Grid *Gd = new Grid(N,M);

    //Checking and parsing for Start Values
    if(fgets(line,32,fptr)==NULL)
    {
        printf("Initial state missing. Exiting ...\n");
        return NULL;   
    }
    argV = parse_line(line,32);
    Gd->Start = Node(argV[1],argV[0],'R');
    Gd->G[argV[1]][argV[0]].col = 'R';
    

    // parsing the goal states into a node vector
    if(fgets(lineG,256,fptr)==NULL)
    {
        printf("Goal state missing. Exiting ...\n");
        return NULL;   
    }
    argV = parse_line(lineG,256);

    for(int i=0;i<argV.size();i+=2) {
        Gd->Goals.push_back(Node(argV[i+1],argV[i],'G'));
        Gd->G[argV[i+1]][argV[i]].col = 'G';
    }

    // parsing the walls
    while(fgets(line,32,fptr)!=NULL)
    {
        argV = parse_line(line,32);
        for(int i=0;i<argV[3];i++){
            for(int j=0;j<argV[2];j++) Gd->G[argV[1]+i][argV[0]+j].col='W';
        }
    }
    
    return Gd;

}
