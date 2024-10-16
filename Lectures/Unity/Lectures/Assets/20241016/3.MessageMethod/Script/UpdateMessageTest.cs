using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UpdateMessageTest : MonoBehaviour
{

    //1. Update : �� �������� ���� ó�� ȣ��ȴ�.
    private float preFrameTime = 0; //���� �������� ȣ��� �ð�.
    private void Update()
    {
        //Time.time : ������ ���۵� �ڷ� 1�ʸ��� 1f�� �ӵ��� ����
        print($"Update ȣ���. �ð� : {Time.time}, ���� �����Ӱ��� �ð����� : {Time.time - preFrameTime}");
        preFrameTime = Time.time;
        print($"delatTime : {Time.deltaTime}");
    }
    /*2. FixedUpdate : ���� ������ �����Ӱ� ������ ���������� ȣ��ɶ����� ȣ��ȴ�.*/
    private float prePhysicsFrameTime = 0;
    private void FixedUpdate()
    {
        print($"FixedUpdate ȣ���. ȣ��ð� : {Time.time}, ���� �����Ӱ� �ð����� : {Time.time - prePhysicsFrameTime}");
        prePhysicsFrameTime = Time.time;
        print($"fixedDelatTime : {Time.fixedDeltaTime}");
    }
    //3. LateUpdate : �� �������� ���� ���߿� ȣ��ȴ�. ���� �����ӿ��� ȣ�� �ǹǷ� Update�� ȣ�� ������ �ٸ����� �ð����̴� ũ�� �ʴ�.
    private float preFrameLateTime = 0;
    private void LateUpdate()
    {
        print($"LateUpdate ȣ���. �ð� : {Time.time}, ���� �����Ӱ��� �ð����� : {Time.time - preFrameLateTime}");
        preFrameLateTime = Time.time;
    }
}
