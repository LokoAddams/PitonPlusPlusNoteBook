// Este codigo usa el triangulo de Pascal para calcular nCr
long long mat[101][101];
long long ncr(long long n, long long r)
{
  if(r == 0 or r == n) return 1;
  
  if(mat[n][r] != 0) 
    return mat[n][r];
  else
  {
    mat[n-1][r-1] = ncr(n-1,r-1);
    mat[n-1][r] = ncr(n-1,r);
    return mat[n-1][r-1] + mat[n-1][r];
  } 
}