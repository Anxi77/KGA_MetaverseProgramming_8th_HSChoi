using System.Collections;
using System.Collections.Generic;
using Unity.Mathematics;
using UnityEngine;

public struct MyStruct 
{

}

public class UnityStructTest : MonoBehaviour
{
    #region 유니티 내장 구조체 : 유니티가 생성한 게임 공간 상에서 빈번하게 쓰이는 데이터 구조체
    //1. Vector2 : 2차원 상에서의 좌표 또는 힘의 크기를 나타내기 위한 구조체
    public Vector2 vector2;
    
    //2. Vector3 : 3차원 상에서의 좌표 또는 힘의 크기를 나타내기 위한 구조체
    public Vector3 vector3;

    //3. Vector4 : 4차원 상에서의 좌표 또는 힘의 크기를 나타내기 위한 구조체
    public Vector4 vector4;

    /*4. Quaternion : 4원수 3차원 축의 값과 1개의 허수부를 이용하여 
     *                3차원 공간에서도 각도 변경 값이 겹치는 "짐벌락" 현상을 방지하기위해 위해 rotation 값으로 사용.
     *                인스펙터에서 보이는 3차원의 앵글을 보려면 euler 앵글을 사용해야 한다.
    */
    public Quaternion quat;

    //5. Vector2(3)Int : 2(3)차원 상에서의 좌표, 정수로 표현할수 있게끔 한다. 
    public Vector2Int v2int;

    //6. Color : 색 인스펙터 상에서 컬러 팔레트로 값을 입력해줄수 있다.
    public Color color;

    #endregion

    void Start()
    {
        print($"{name}'s position : {transform.position}");
        print($"{name}'s position : {transform.localScale}");  
        print($"{name}'s position : {transform.rotation}");
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
