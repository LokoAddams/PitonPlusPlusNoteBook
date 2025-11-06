vi acu(int(1e5));
int c(int l, int r)
{
  if(l > 0) return acu[r] - acu[l-1];
  return acu[r];
}

int t ;
int bs(int l, int r)
{
  int i = l, j = r;
  int n , mitad;
  while (i != j)
  {
    n = j - i;
    mitad = i + n/2;
    if(c(l,mitad) == t) return mitad - l + 1;
    if(c(l,mitad) > t) j = mitad;
    else i = mitad + 1;
  }
  return c(l,i) <= t ? i - l + 1 : (c(l,i - 1) ? i - l : - 1) ;  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  icin(n)
  cin >> t;
  vi nums(n);
  form(i,0,n) cin >> nums[i];

  acu[0] = nums[0];
  form(i,1,n) acu[i] = acu[i-1] + nums[i];
  int maxi = 0;
  form(i,0,n)
    maxi = max(maxi , bs(i, n-1));
  cout << maxi << endl;
  return 0;
}