using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp03
{

    /*Sorting Algorithms
     *Bubble Sort
     * 전체 배열을 돌면서 항목이 다른 항목보다 큰 경우 두 항목을 교환.
     * 가장 간단한 정렬 알고리즘이다.
     * 오름차순이나 내림차순으로 정렬된다.
     * 비교와 교환이 빈번하게 발생하기에 속도가 느리다.
     * 정렬이 되어있는 경우에도 정렬이 발생하기에 비효율적일 수 있다.
     
     *분할정복
     * 큰 문제를 작은 하위 문제로 분할하여 해결하고 그 하위 문제들의 해답을 조합하여 전체 문제의 해답을 얻는것
     
     * 1. 분할 : 원래 문제를 작은 하위문제들로 분할
     * 보통 재귀적인 방법으로 이루어지고 원래 문제를 해결하기 위해 여러 하위문제들로 분할된다.
     
     * 2. 정복 : 각 하위 문제를 재귀적으로 해결.
     * 하위 문제의 크기가 충분히 작아서 직접 해결할 수 있는 경우에 해당한다.
     
     * 3. 결함 : 각 하위 문제의 해답을 결합하여 원래 문제의 해답을 얻는다
     * 이 단계에서는 분할된 하위 문제들의 해답을 조합하여 전체 문제의 해답을 생성
      
     * 2^8
     * 2^4 , 2^4
     * 2^2 * 2^2
      
     *Quick Sort
     * 퀵 정렬의 핵심은 주어진 배열을 pivot을 기준으로 작은 값은 왼쪽, 큰 값은 오른쪽으로 나누어 정렬한다.
     * 주어진 배열을 특정 pivot 값을 기준으로 두개의 서브배열로 분할하고 , 각 서브배열을 재귀적으로 정렬하여
     * 최종적으로 정렬된 배열을 얻는 알고리즘.
     */

    internal class Sort
    {
        #region BubbleSort
        static int[] BubbleSort(int[] arr)
        {
            for (int i = 0; i < arr.Length; i++)
            {
                /*각 반복에서 가장 큰 요소가 맨 뒤로 이동하므로
                끝 인덱스는 감소하여 반복횟수를 줄인다*/
                for (int k = 0; k < arr.Length - i - 1; k++)
                {
                    //현재 요소와 다음 요소를 비교하여 정렬이 필요한 경우 스왑

                    if (arr[k] > arr[k + 1])
                    {
                        Swap(arr, k, k + 1); //두 요소의 위치를 스왑
                    }
                }
            }
            return arr; //정렬된 배열을 리턴
        }
        #endregion
        #region QuickSort
        static void QuickSort(int[] items)
        {
            QuickSortHelper(items, 0, items.Length - 1);
        }
        static void QuickSortHelper(int[] items, int left, int right)
        {

            while (left < right)
            {
                //배열을 분할하고 분할 인덱스를 받는다.
                int partitionIndex = Partition(items, left, right);

                //분할된 배열의 왼쪽 부분에 재귀적으로
                if (partitionIndex - left < right - partitionIndex)
                {
                    QuickSortHelper(items, left, partitionIndex - 1);
                    left = partitionIndex + 1;
                }
                else
                {
                    QuickSortHelper(items, partitionIndex + 1, right);
                    right = partitionIndex - 1;
                }
            }

        }
        //배열을 분할하고 분할 인덱스를 반환하는 메서드
        static int Partition(int[] arr, int left, int right)
        {
            // 중간 값을 피벗으로 선택
            int pivotIndex = (left + right) / 2;
            int pivotValue = arr[pivotIndex];

            // 피벗을 맨 오른쪽으로 이동
            Swap(arr, pivotIndex, right);

            int storeIndex = left;

            // 여기서 i는 left부터 시작해야 합니다
            for (int i = left; i < right; i++)
            {
                if (arr[i] < pivotValue)
                {
                    // 현재값이 피봇보다 작으면 해당값을 storeIndex에 위치한 값과 교환
                    Swap(arr, i, storeIndex);
                    storeIndex++;
                }
            }

            // 피벗을 올바른 위치로 이동
            Swap(arr, storeIndex, right);

            return storeIndex;
        }
        #endregion
        //테스트용 Swap
        static void Swap(int[] arr, int idx1, int idx2)
        {
            int temp = arr[idx1];
            arr[idx1] = arr[idx2];
            arr[idx2] = temp;
        }
        static void Main(string[] args)
        {
            Random random = new Random();
            int[] data = new int[100];

            for (int i = 0; i < data.Length; i++)
            {
                data[i] = random.Next(100);
            }

            Stopwatch sw = Stopwatch.StartNew();

            QuickSort(data);

            sw.Stop();

            double seconds = sw.Elapsed.TotalSeconds;

            Console.WriteLine($"정렬에 걸린 시간 : {seconds} 초");
        }
    }
}
