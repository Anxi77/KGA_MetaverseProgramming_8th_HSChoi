using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MessageMethodTest : MonoBehaviour
{
    #region Message Function(Event Function)
    /*메시지 함수(이벤트 함수) : 개발자가 직접 호출하지 않아도 유니티 게임 프로세스상 발생하는 이벤트에 따라 유니티 엔진이 호출해주는 함수.
      함수 이름과 파라미터가 정해져 있으며, 함수 종류마다 호출 조건이 다르다.
     */

    /*0. Awake : 객체가 로드되자마자 호출된다.
      주의 : 해당 GameObject 내의 다른 컴포넌트는 접근 가능하지만 , 
            다른 GameObject는 아직 로드가 안되어서 접근이 불가능할 가능성이 있음 
            그러므로 해당 컴포넌트가 부착된 게임 오브젝트를 초기화 할 용도로 사용
     */
    private BoxCollider boxCollider;

    private void Awake()
    {
        boxCollider = GetComponent<BoxCollider>();

        if(transform.position.y > 1) 
        {
            boxCollider.center = new Vector3(0, -1, 0);
        }
    }

    //1. Start : 게임이 로드 된 후, 가장 첫 프레임 시작 직전에 호출된다.
    private string state = "Not Ready";
    private bool isInit = false;

    private void Start()
    {
        print("Start 메시지 함수 호출.");
        state = "Ready";
        isInit = true;
    }


    //2. Update : 게임이 로드 된 후, 매 프레임마다 한번씩 호출.
    public int frameCount = 0;
    private void Update()
    {
        //print($"Update 메시지 함수 호출 . {framecount++}");
    }
    
    /*3. OnEnable/OnDisable : 해당 객체 또는 컴포넌트가 활성화 되거나 비활성화 되면 호출. 
    주의 : OnEnable()은 객체 로드가 완료된 후에 즉시 호출되므로, 처음 1회는 Start 함수보다 먼저 호출된다.
    이경우의 팁 : 이 컴포넌트의 초기화 수행 여부를 체크해주면 좋다.
     */
    private void OnEnable()
    {
        if (false == isInit) return;
        print("OnEnable 함수 호출.");
        print($"현재 객체 상태 {state}");
    }
    private void OnDisable()
    {
        print("OnDisable 함수 호출.");
    }

    /*4. OnDestroy : 게임 오브젝트 또는 컴포넌트가 파괴될때 호출.
     주의 : 호출되기 전 OnDisable()이 먼저 호출된다.
     */
    private void OnDestroy()
    {
        print("OnDestroy 함수 호출");
    }
    #endregion

}
