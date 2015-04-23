package qt.android.support.v7.widget;

import android.view.View;
import android.view.ViewGroup;
import android.support.v7.widget.RecyclerView;

import java.lang.Integer;

public class QmlRecyclerAdapter extends RecyclerView.Adapter<QmlRecyclerAdapter.ViewHolder>
{
    public QmlRecyclerAdapter(int count, long instance) {
        m_count = count;
        m_instance = instance;
    }

    @Override
    public int getItemCount() {
        return m_count;
    }

    public void setItemCount(int count) {
        if (m_count != count) {
            m_count = count;
            notifyDataSetChanged();
        }
    }

    public static class ViewHolder extends RecyclerView.ViewHolder
    {
        public ViewHolder(View view, long instance) {
            super(view);
            m_instance = instance;
        }
        public long getInstance() {
            return m_instance;
        }
        private long m_instance;
    }

    @Override
    public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        ViewHolder vh = onCreateViewHolder(m_instance, parent, viewType);
        // TODO:
        RecyclerView.LayoutParams params = new RecyclerView.LayoutParams(-1, -2);
        vh.itemView.setLayoutParams(params);
        return vh;
    }

    @Override
    public void onBindViewHolder(ViewHolder holder, int position) {
        onBindViewHolder(m_instance, holder, position);
    }

    @Override
    public void onViewRecycled(ViewHolder holder) {
        // TODO
    }

    private int m_count;
    private long m_instance;
    private static native ViewHolder onCreateViewHolder(long instance, ViewGroup parent, int viewType);
    private static native void onBindViewHolder(long instance, ViewHolder holder, int position);
}
