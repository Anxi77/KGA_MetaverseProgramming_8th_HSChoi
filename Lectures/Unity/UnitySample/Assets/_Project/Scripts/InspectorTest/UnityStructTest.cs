using System.Collections;
using System.Collections.Generic;
using Unity.Mathematics;
using UnityEngine;

public struct MyStruct 
{

}

public class UnityStructTest : MonoBehaviour
{
    #region ����Ƽ ���� ����ü : ����Ƽ�� ������ ���� ���� �󿡼� ����ϰ� ���̴� ������ ����ü
    //1. Vector2 : 2���� �󿡼��� ��ǥ �Ǵ� ���� ũ�⸦ ��Ÿ���� ���� ����ü
    public Vector2 vector2;
    
    //2. Vector3 : 3���� �󿡼��� ��ǥ �Ǵ� ���� ũ�⸦ ��Ÿ���� ���� ����ü
    public Vector3 vector3;

    //3. Vector4 : 4���� �󿡼��� ��ǥ �Ǵ� ���� ũ�⸦ ��Ÿ���� ���� ����ü
    public Vector4 vector4;

    /*4. Quaternion : 4���� 3���� ���� ���� 1���� ����θ� �̿��Ͽ� 
     *                3���� ���������� ���� ���� ���� ��ġ�� "������" ������ �����ϱ����� ���� rotation ������ ���.
     *                �ν����Ϳ��� ���̴� 3������ �ޱ��� ������ euler �ޱ��� ����ؾ� �Ѵ�.
    */
    public Quaternion quat;

    //5. Vector2(3)Int : 2(3)���� �󿡼��� ��ǥ, ������ ǥ���Ҽ� �ְԲ� �Ѵ�. 
    public Vector2Int v2int;

    //6. Color : �� �ν����� �󿡼� �÷� �ȷ�Ʈ�� ���� �Է����ټ� �ִ�.
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
