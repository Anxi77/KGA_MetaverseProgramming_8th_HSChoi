/*
[과제]
    collection에 대해 정리 후 발표
    제네릭타입 , 비 제네릭 타입
    종류와 각각의 특징을 면밀히 조사하여 발표예정.

k개의 공통된 배열 찾기

입력 
int[] arr = {1,5,5,10};
int[] arr2 = {3,4,5,5,10};
int[] arr3 = {5,5,10,20};

결과
5,10
 */

namespace _20241010
{
    internal class FindSameElements
    {
        public static int[] HashSetFindSameElements(Dictionary<int, int[]> Arrays) 
        {
            // 입력된 모든 배열 중 첫 번째 배열을 선택하여 HashSet commonElements로 데이터를 추출.
            // HashSet은 중복을 허용하지 않아 같은 요소가 여러 번 등장해도 하나만 존재하게 됨.
            HashSet<int> commonElements = new HashSet<int>(Arrays[0]);
          
            //첫번째 배열 이외의 모든 배열에 요소의 교집합을 순회
            for (int i = 1; i < Arrays.Count; i++)
            {
                //현재의 공통 요소와 다음 배열의 요소들간의 교집합으로 공통된 요소를 추출.
                commonElements.IntersectWith(Arrays[i]);
            }
            string
            //HashSet commonElements를 배열로 return
            return commonElements.ToArray();
        }
        public static int[] NativeFindSameElements(Dictionary<int, int[]> Arrays) 
        {
            //아무런 배열을 입력하지 않았다면 빈 배열을 리턴
            if(Arrays.Count == 0) 
            {
                return Array.Empty<int>();
            }

            //첫번째 배열을 담은 변수 firstArray 선언/정의
            int[] firstArray = Arrays.Values.First();
            //중복된 요소를 담을 리스트 선언 및 초기화(공통된 요소의 갯수를 모르기 때문에 리스트로 선언)
            List<int> commonElements = new List<int>();

            //첫번째 배열의 모든 요소들을 순회하며
            foreach(int element in firstArray) 
            {
                //중복인 요소를 판정할 boolean 변수 isCommon을 true로 초기화
                bool isCommon = true;
                
                //첫번째 배열을 제외한 나머지 배열들을 순회하며
                foreach (var array in Arrays.Values.Skip(1)) 
                {
                    //만약 첫번째 요소의 element가 순회하고 있는 배열의 요소에 존재하지 않는다면
                    if (!Array.Exists(array, x => x == element))
                    {
                        //isCommon에 false를 대입 후
                        isCommon = false;
                        //탈출
                        break;
                    }
                }

                /*element 에 대한 비교를 하는 위의 반복문을 다 돌고(element 에 대한 다른 배열의 요소들과의 중복 비교가 끝나고)
                만약 현재의 commonElements의 안에 element가 없으면서 중복이 된다면
                commonElements 에 element를 추가한다.*/
                if(isCommon && !commonElements.Contains(element)) 
                {
                    commonElements.Add(element);
                }
            }

            
            return commonElements.ToArray();
        }
        static void Main(string[] args)
        {
            Console.Write("입력하실 배열의 갯수를 입력하시오 : ");
            int arrNums = int.Parse(Console.ReadLine());
            //int 의 key(배열을 담을 인덱스) 와 int[] 배열의 밸류로 이루어진 딕셔너리 생성
            Dictionary<int, int[]> Arrays = new Dictionary<int, int[]>();

            //i의 키를 갖고 배열 array를 밸류로 입력
            for(int i = 0; i < arrNums; i++) 
            {
                Console.WriteLine($"{i + 1}번째 배열의 요소를 공백으로 구분하여 입력하세요:");
                string[] input = Console.ReadLine().Split(' ');
                int[] array = Array.ConvertAll(input, int.Parse);
                Arrays.Add(i, array);
            }


            //int[] result = HashSetFindSameElements(Arrays);
            int[] result = NativeFindSameElements(Arrays);
            //string.join으로 배열의 요소들을 " , " 을 구분으로 출력
            if (result.Length > 0)
            {
                Console.WriteLine("공통 요소 : " + string.Join(" , ", result));
                /*string.Join
                 1.기본 타입
                   정수, 실수, 문자열 등의 기본 타입은 자동으로 문자열로 변환.
                 2.객체 배열
                   객체의 경우 ToString() 메서드가 호출.
                   만약 ToString()이 오버라이드되지 않았다면, 객체의 타입 이름이 출력될 수 있음.
                 3.null 값
                   null 값은 빈 문자열로 처리
                 4.복잡한 객체의 경우 원하는 속성만 문자열로 변환 필요.
                    var people = new List<Person> { new Person("Kim"), new Person("Lee") };
                    string result = string.Join(", ", people.Select(p => p.Name));
                 5.
                 */
            }
            else
            {
                Console.WriteLine("배열을 입력하지 않으셨습니다 . 종료");
            }
        }
    }
}
