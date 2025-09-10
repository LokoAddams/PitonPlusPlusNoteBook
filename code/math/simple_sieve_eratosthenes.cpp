#define tam 1e7
vector < bool > criba(tam , true);

void criba_function()
{
  criba[0]=false;
  criba[1]=false;
  //( i*i < tam) equivalente a (i <= sqrt(tam)) 
  for(int i = 2; i*i <= tam ; i++)
  {
    if(!criba[i]) continue;
    for(int j = 2; i*j <= tam ; j++)
      criba[i * j] = false;
  }
}
