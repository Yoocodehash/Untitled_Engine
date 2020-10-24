/*
position += velocity * deltaTime + 0.5f * acceleration * pow(deltaTime, 2)

public void UpdatePhysics()
{
    mOldPosition = mPosition;
    mOldSpeed = mSpeed;

    mWasOnGround = mOnGround;
    mPushedRightWall = mPushesRightWall;
    mPushedLeftWall = mPushesLeftWall;
    mWasAtCeiling = mAtCeiling;
}

if (KeyState(KeyInput.GoRight) == KeyState(KeyInput.GoLeft))
{
    mCurrentState = CharacterState.Stand;
    mSpeed = Vector2.zero;
    break;
}
else if (KeyState(KeyInput.GoRight))
{
    if (mPushesRightWall)
        mSpeed.x = 0.0f;
    else
        mSpeed.x = mWalkSpeed;

    mScale.x = Mathf.Abs(mScale.x);
}
else if (KeyState(KeyInput.GoLeft))
{
    if (mPushesLeftWall)
        mSpeed.x = 0.0f;
    else
        mSpeed.x = -mWalkSpeed;

    mScale.x = -Mathf.Abs(mScale.x);
}



public class MovingObject
{
    public Vector2 mOldPosition;
    public Vector2 mPosition;

    public Vector2 mOldSpeed;
    public Vector2 mSpeed;

    public Vector2 mScale;
}

public bool Overlaps(AABB other)
{
    if (Mathf.Abs(center.x - other.center.x) > halfSize.x + other.halfSize.x) return false;
    if (Mathf.Abs(center.y - other.center.y) > halfSize.y + other.halfSize.y) return false;
    return true;
}






public void CharacterUpdate()
{
    switch (mCurrentState)
    {
    case CharacterState.Stand:

        mWalkSfxTimer = cWalkSfxTime;
        mAnimator.Play("Stand");

        mSpeed = Vector2.zero;

        if (!mOnGround)
        {
            mCurrentState = CharacterState.Jump;
            break;
        }

        if (KeyState(KeyInput.GoRight) != KeyState(KeyInput.GoLeft))
        {
            mCurrentState = CharacterState.Walk;
            break;
        }
        else if (KeyState(KeyInput.Jump))
        {
            mSpeed.y = mJumpSpeed;
            mAudioSource.PlayOneShot(mJumpSfx);
            mCurrentState = CharacterState.Jump;
            break;
        }

        break;
    case CharacterState.Walk:
        mAnimator.Play("Walk");

        mWalkSfxTimer += Time.deltaTime;

        if (mWalkSfxTimer > cWalkSfxTime)
        {
            mWalkSfxTimer = 0.0f;
            mAudioSource.PlayOneShot(mWalkSfx);
        }


        if (KeyState(KeyInput.GoRight) == KeyState(KeyInput.GoLeft))
        {
            mCurrentState = CharacterState.Stand;
            mSpeed = Vector2.zero;
            break;
        }
        else if (KeyState(KeyInput.GoRight))
        {
            if (mPushesRightWall)
                mSpeed.x = 0.0f;
            else
                mSpeed.x = mWalkSpeed;
            mScale.x = -Mathf.Abs(mScale.x);
        }
        else if (KeyState(KeyInput.GoLeft))
        {
            if (mPushesLeftWall)
                mSpeed.x = 0.0f;
            else
                mSpeed.x = -mWalkSpeed;
            mScale.x = Mathf.Abs(mScale.x);
        }

        if (KeyState(KeyInput.Jump))
        {
            mSpeed.y = mJumpSpeed;
            mAudioSource.PlayOneShot(mJumpSfx, 1.0f);
            mCurrentState = CharacterState.Jump;
            break;
        }
        else if (!mOnGround)
        {
            mCurrentState = CharacterState.Jump;
            break;
        }

        break;
    case CharacterState.Jump:

        mWalkSfxTimer = cWalkSfxTime;

        mAnimator.Play("Jump");

        mSpeed.y += Constants.cGravity * Time.deltaTime;

        mSpeed.y = Mathf.Max(mSpeed.y, Constants.cMaxFallingSpeed);

        if (!KeyState(KeyInput.Jump) && mSpeed.y > 0.0f)
        {
            mSpeed.y = Mathf.Min(mSpeed.y, 200.0f);
        }

        if (KeyState(KeyInput.GoRight) == KeyState(KeyInput.GoLeft))
        {
            mSpeed.x = 0.0f;
        }
        else if (KeyState(KeyInput.GoRight))
        {
            if (mPushesRightWall)
                mSpeed.x = 0.0f;
            else
                mSpeed.x = mWalkSpeed;
            mScale.x = -Mathf.Abs(mScale.x);
        }
        else if (KeyState(KeyInput.GoLeft))
        {
            if (mPushesLeftWall)
                mSpeed.x = 0.0f;
            else
                mSpeed.x = -mWalkSpeed;
            mScale.x = Mathf.Abs(mScale.x);
        }

        if (mOnGround)
        {
            if (mInputs[(int)KeyInput.GoRight] == mInputs[(int)KeyInput.GoLeft])
            {
                mCurrentState = CharacterState.Stand;
                mSpeed = Vector2.zero;
                mAudioSource.PlayOneShot(mHitWallSfx, 0.5f);
            }
            else
            {
                mCurrentState = CharacterState.Walk;
                mSpeed.y = 0.0f;
                mAudioSource.PlayOneShot(mHitWallSfx, 0.5f);
            }
        }
        break;

    case CharacterState.GrabLedge:
        break;
    }

    UpdatePhysics();

    if ((!mWasOnGround && mOnGround)
        || (!mWasAtCeiling && mAtCeiling)
        || (!mPushedLeftWall && mPushesLeftWall)
        || (!mPushedRightWall && mPushesRightWall))
        mAudioSource.PlayOneShot(mHitWallSfx, 0.5f);

    UpdatePrevInputs();
}
*/