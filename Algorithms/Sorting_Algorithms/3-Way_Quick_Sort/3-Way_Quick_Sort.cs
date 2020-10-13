
using System;

class Sort {
	
	static void swap<T>(ref T lhs, ref T rhs)
	{
		T temp;
		temp = lhs;
		lhs = rhs;
		rhs = temp;
	}

	public static void partition(int[] a, int l, int r, ref int i, ref int j)
	{
		i = l - 1;
		j = r;
		int p = l - 1, q = r;
		int v = a[r];

		while (true) {
			
			while (a[++i] < v)
				;

			while (v < a[--j])
				if (j == l)
					break;

		
			if (i >= j)
				break;

		
			swap(ref a[i], ref a[j]);

			
			if (a[i] == v) {
				p++;
				swap(ref a[p], ref a[i]);
			}

			
			if (a[j] == v) {
				q--;
				swap(ref a[j], ref a[q]);
			}
		}


		swap(ref a[i], ref a[r]);

		j = i - 1;
		for (int k = l; k < p; k++, j--)
			swap(ref a[k], ref a[j]);

		i = i + 1;
		for (int k = r - 1; k > q; k--, i++)
			swap(ref a[i], ref a[k]);
	}


	public static void quicksort(int[] a, int l, int r)
	{
		if (r <= l)
			return;

		int i = 0, j = 0;


		partition(a, l, r, ref i, ref j);

		quicksort(a, l, j);
		quicksort(a, i, r);
	}

	
	public static void printarr(int[] a, int n)
	{
		for (int i = 0; i < n; ++i)
			Console.Write(a[i] + " ");
		Console.Write("\n");
	}

	
	static void Main()
	{
		int[] a = { 4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4 };
		int size = a.Length;
		
		
		printarr(a, size);
		quicksort(a, 0, size - 1);
		printarr(a, size);
	}
}
