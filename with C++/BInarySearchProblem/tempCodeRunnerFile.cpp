bool isValid(int arr[], int mid, int n, int k)
{
    int sum;
    int student = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > mid)
        {
            sum = arr[i];
            student++;
        }
        
        if (k == student)
        {
            return false;
        }
    }
    return true;
}