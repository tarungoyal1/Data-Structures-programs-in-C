using System;

namespace Heapsort
{
	class Program
	{
	
		
		public static void Main(string[] args)
		{
			Console.WriteLine("Enter the size of the heap:");
			
			int n = Int32.Parse(Console.ReadLine());
			
			Heap h = new Heap();
			
			h.heap = new int[n+1];
			
			Console.WriteLine("Enter the elements in heap:");
			
			for(int i=1;i<=n;i++)
				h.heap[i]  = Int32.Parse(Console.ReadLine());
			
			Heap_sort(h, n);
							
			Console.WriteLine("\nPress any key to continue . . . ");
			Console.ReadKey(true);
		}
		
		public static void Heap_sort(Heap h, int n){
			
			
			Build_Max_heap(h, n);
			Console.WriteLine("Max heap:");
			for(int i=1;i<=n;i++)
				Console.Write(h.heap[i]+", ");
			
			
			int heapsize =n;
			int [] sorted = new int[n+1];
			for(int i=n;i>0;i--){
				swap(h, i, 1);
				sorted[heapsize]=h.heap[heapsize];
				Max_heapify(h, 1, --heapsize);
			}
			
			Console.WriteLine("\nSorted array:");
			for(int i=1;i<=n;i++)
				Console.Write(sorted[i]+", ");
		}
		
		public static void Build_Max_heap(Heap h, int n){
			for(int i=n/2;i>0;i--)
				Max_heapify(h, i, n);
		
		}
		
		public static void swap(Heap h, int a, int b){
			int temp = h.heap[a];
			h.heap[a] = h.heap[b];
			h.heap[b] = temp;
		}
		
		public static void Max_heapify(Heap h, int i, int n){
			int largest = i;
			int l = 2*i;
			int r = 2*i+1;
			
			if(l<=n&&h.heap[l]>h.heap[largest])
				largest = l;
			if(r<=n&&h.heap[r]>h.heap[largest])
				largest = r;
			if(largest != i){
				swap(h, i, largest);
				Max_heapify(h, largest, n);
				
			}			
			
		}
	}
	class Heap{
		public int [] heap;
	}
}