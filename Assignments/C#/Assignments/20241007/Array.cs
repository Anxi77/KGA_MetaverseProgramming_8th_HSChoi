/*20241007 과제
4.배열
ㄴ학생성적 입력받아 배열에 저장
ㄴ입력된 성적중 가장 높은 성적과 낮은 성적 출력
ㄴ평균 성적 계산
ㄴ오름차순 정렬
5.문자열 내 단어 뒤집기
ㄴ문자열을 입력받고 해당 문자열의 간 단어를 뒤집는다.
ㄴ입력예시)"abcd efgh"
ㄴ출력예시)dcba hgfe
*/

using System.ComponentModel;
using System.Security.Cryptography;

namespace _20241007
{
    internal class Program
    {
        /*문자열 뒤집기*/
        static void RevString(string input)
        {
            string[] sepinput = input.Split(' ');

            foreach (var revword in sepinput)
            {
                string RevRes = new string(revword.Reverse().ToArray());
                Console.WriteLine(RevRes);
            }

        }
        static void revSepWord()
        {
            string revinput = "abcd efgh";
            RevString(revinput);

        }
        /*학생성적 평균 , 정렬*/

        class Points
        {
            public int Math;
            public int Science;
            public int English;

            public Points(int math, int science, int english)
            {
                this.Math = math;
                this.Science = science;
                this.English = english;
            }
        }
        class Student
        {
            public Points P;
            public string Name;
            public double Average;

            public Student(int math, int science, int english, string name)
            {
                this.P = new Points(math, science, english);
                this.Name = name;
                this.Average = (P.Math + P.Science + P.English) / 3;
            }
        }
        static void SortAverage(Student[] students)
        {
            int MathSum = 0;
            int ScienceSum = 0;
            int EnglishSum = 0;
            int MathAverage = 0;
            int ScienceAverage = 0;
            int EnglishAverage = 0;
            int Average = 0;
            int AvSum = 0;

            foreach (var student in students)
            {
                MathSum += student.P.Math;
            }
            foreach (var student in students)
            {
                EnglishSum += student.P.English;
            }
            foreach (var student in students)
            {
                ScienceSum += student.P.Science;
            }

            MathAverage = MathSum / students.Length;
            EnglishAverage = MathSum / students.Length;
            ScienceAverage = MathSum / students.Length;
            Average = AvSum / students.Length;
            Array.Sort(students, (s1, s2) => s1.Average.CompareTo(s2.Average));

            Console.WriteLine("[학생의 성적]");
            foreach (var student in students)
            {
                Console.WriteLine("학생 이름: {0}, 수학: {1}, 과학: {2}, 영어: {3} 평균: {4}",
                    student.Name, student.P.Math, student.P.Science, student.P.English, student.Average);
            }

            Console.WriteLine("학생들의 총 수학 성적 평균: {0}", MathAverage);
            Console.WriteLine("학생들의 총 영어 성적 평균: {0}", EnglishAverage);
            Console.WriteLine("학생들의 총 과학 성적 평균: {0}", ScienceAverage);
        }

        static void StudentPoints()
        {
            Student[] students = new Student[3];
            for (int i = 0; i < students.Length; i++)
            {
                Console.Write("학생의 이름을 입력해주세요 : ");
                string name = Console.ReadLine();

                Console.Write("수학 성적을 입력해주세요 : ");
                int math = int.Parse(Console.ReadLine());

                Console.Write("과학 성적을 입력해주세요 : ");
                int science = int.Parse(Console.ReadLine());

                Console.Write("영어 성적을 입력해주세요 : ");
                int english = int.Parse(Console.ReadLine());

                students[i] = new Student(math, science, english, name);
            }

            SortAverage(students);
        }

        static void Main(string[] args)
        {
            StudentPoints();
        }
    }
    
}
