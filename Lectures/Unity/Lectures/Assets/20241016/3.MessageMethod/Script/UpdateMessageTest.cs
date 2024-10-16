using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UpdateMessageTest : MonoBehaviour
{

    //1. Update : 매 프레임의 가장 처음 호출된다.
    private float preFrameTime = 0; //이전 프레임이 호출된 시간.
    private void Update()
    {
        //Time.time : 게임이 시작된 뒤로 1초마다 1f의 속도로 누적
        print($"Update 호출됨. 시간 : {Time.time}, 이전 프레임과의 시간차이 : {Time.time - preFrameTime}");
        preFrameTime = Time.time;
        print($"delatTime : {Time.deltaTime}");
    }
    /*2. FixedUpdate : 게임 로직상 프레임과 별개로 물리연산이 호출될때마다 호출된다.*/
    private float prePhysicsFrameTime = 0;
    private void FixedUpdate()
    {
        print($"FixedUpdate 호출됨. 호출시간 : {Time.time}, 이전 프레임과 시간차이 : {Time.time - prePhysicsFrameTime}");
        prePhysicsFrameTime = Time.time;
        print($"fixedDelatTime : {Time.fixedDeltaTime}");
    }
    //3. LateUpdate : 매 프레임의 가장 나중에 호출된다. 동일 프레임에서 호출 되므로 Update와 호출 순서는 다르지만 시간차이는 크지 않다.
    private float preFrameLateTime = 0;
    private void LateUpdate()
    {
        print($"LateUpdate 호출됨. 시간 : {Time.time}, 이전 프레임과의 시간차이 : {Time.time - preFrameLateTime}");
        preFrameLateTime = Time.time;
    }
}
