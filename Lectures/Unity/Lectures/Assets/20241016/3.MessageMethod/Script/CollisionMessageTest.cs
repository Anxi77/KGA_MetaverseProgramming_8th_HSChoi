using System.Collections;
using System.Collections.Generic;
using UnityEngine;



public class CollisionMessageTest : MonoBehaviour
{
    #region 물리적인 충돌 또는 상호작용에 의해서 호출되는 메세지 테스트
    /* OnCollsionXX 메세지 호출 조건 : 호출 될 컴포넌트에 Collider 컴포넌트가 존재해야 하며,
     * 충돌 메시지 함수를 호출하는 객체가 Rigidbody 이므로 , 충돌한 두 오브젝트 중 한에는 꼭 Rigidbody가 붙어 있어야 호출된다.
     */
    //1. OnCollisionEnter : 물리적인 충돌이 일어났을때 호출 *Collsion 클래스 : 충돌 자체의 정보(위치 속도 등등)을 담고있는 클래스이다.
    private void OnCollisionEnter(Collision collision)
    {
        Collider otherCollider = collision.collider; //충돌을 일으킨 대상

        print($"충돌이 일어남. 호출 주체 {name}, 충돌 대상 : {otherCollider.name}");
    }

    //2. OnCollisionExit : 충돌 되었던 Collider가 다시 충돌상태가 아니게 되면 호출.
    private void OnCollisionExit(Collision coll)
    {
        print($"충돌했다가 떨어짐. 호출 주체 {name}, 충돌 대상 : {coll.collider.name}");
    }

    //3. OnCollsionStay : 충돌중일때 프레임마다 호출.
    private void OnCollisionStay(Collision c)
    {
        print($"충돌하는중. 호출 주체 {name}, 충돌 대상 : {c.collider.name}");
    }
    #endregion
}
