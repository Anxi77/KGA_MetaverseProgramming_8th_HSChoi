namespace UserDataType
{
    internal class Program
    {
        /*열거형 (C++와 동일하다)*/
        enum Direction 
        {
            Up, Down, Left, Right
        }
        /*구조체 (C++와 동일/값형식)*/
        struct StudentInfo
        {
            public string name;
            public int math;
            public int english;
            public int science;

            public float Average()
            {
                return (math + english + science) / 3.0f;
            }
        }
        struct Point
        {
            public int x;
            public int y;

            public Point(int x, int y)
            {
                this.x = x;
                this.y = y;
            }
        }

        static void Main(string[] args)
        {
          Direction dir = Direction.Up;

            switch (dir)
            {
                case Direction.Up:
                    break;
                case Direction.Down:
                    break;
                case Direction.Left:
                    break;
                case Direction.Right:
                    break;
                default:
                    break;
            }
        }
    }
}
