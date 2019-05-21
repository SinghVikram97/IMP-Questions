long maxPathSum(int ar1[], int ar2[], int m, int n)
{

  int i = 0, j = 0;
  long sum1 = 0, sum2 = 0, sum = 0;
  while (i < m && j < n)
  {

    if (ar1[i] < ar2[j])
    {
      sum1 = sum1 + ar1[i];
      i++;
    }
    else if (ar2[j] < ar1[i])
    {
      sum2 = sum2 + ar2[j];
      j++;
    }
    // Both elements same
    else
    {
      sum = sum + max(sum1, sum2);
      sum1 = 0;
      sum2 = 0;
      while (i < m && j < n && ar1[i] == ar2[j])
      {
        sum = sum + ar1[i];
        i++;
        j++;
      }
    }
  }
  while (i < m)
  {
    sum1 = sum1 + ar1[i];
    i++;
  }
  while (j < n)
  {
    sum2 = sum2 + ar2[j];
    j++;
  }

  sum = sum + max(sum1, sum2);

  return sum;
}
