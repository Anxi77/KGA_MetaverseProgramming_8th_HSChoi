namespace Csharp04
{
    /*인덱서
     * this[]를 속성으로 정의하여 클래스의 인스턴스에 인덱스 방식으로 접근할수 있게 해준다.
     * 클래스나 구조체가 배열처럼 인덱스를 사용하여 접근할수 있게 해준다.
     * 배열과 비슷하게 동작하지만 get , set을 통하여 동작한다.
     */
    internal class Indexer
    {
        class IndexerArray
        {
            private int[] array = new int[10];

            //인덱서 정의
            public int this[int index] 
            {
                get 
                {
                    return array[index];
                }
                set 
                {
                    array[index] = value;
                }
            }
        }
        static void Test01() 
        {
           IndexerArray array = new IndexerArray();

           //인덱서를 통한 접근을 허용한다.
           array[5] = 1;
        }

        public enum Parts { Head, Body, Feet, Hand, SIZE }

        class Equipment
        {
            string[] parts = new string[(int)Parts.SIZE];

            public string this[Parts type]
            {
                get
                {
                    return parts[(int)type];
                }
                set
                {
                    parts[(int)type] = value;
                }

            }
        }
        static void Test02() 
        {
            Equipment equipment = new Equipment();

            equipment[Parts.Head] = "낡은 뚜껑";
            equipment[Parts.Feet] = "가죽 장화";

            Console.WriteLine($"착용하고 있는 헬멧 {equipment[Parts.Head]}");
        }
        static void Main(string[] args)
        {
            
        }
    }
}
